/*
 * badge.ino - Main badge sketch
 * Charles Lehman - 2016-07-24
 * 
 * Can be controlled by 115200 8N1 serial over default hardware serial pins; see below for available commands
 * Digital 2-9 are the 8 LEDs, in counter-clockwise order, starting with the one at the top of the "d" (active HIGH)
 * Controls a display module over SPI with default hardware MISO/MOSI/SCK pins and #CS on digital 10
 */

#include <SPI.h>
#include "Arduino.h"
#include "DisplayProtocol.h"
#include "FlashData.h"

const int FIRST_LED = 2;
const int LED_COUNT = 8;
const int SPI_CS_PIN = 10;
const uint16_t MAX_ROTATION = LED_COUNT * 256;

// NOTE: if setting ledDim[n] to 0, ledPdm[n] needs to be set to non-zero or the LED will be on
uint8_t ledDim[LED_COUNT];
uint8_t ledPdm[LED_COUNT];
#define LED_PIN(n) (FIRST_LED + (n))

#define SERIAL_PROMPT (F("\n> "))

#define COMMAND_DELIMITERS " "

// NOTE: serialLine is declared as size RX_BUF_LEN + 1 to accomodate null terminator
#define RX_BUF_LEN 63
char serialLine[RX_BUF_LEN + 1];
uint8_t serialPtr = 0;
uint8_t textBlockLines = 0;
uint8_t textBlockPtr = 0;

// EEPROM and configuration data accessor
FlashData flash;

struct {
  unsigned long nextFrame;
  unsigned long nextAnimation;
  int16_t rotatePosition;
} animationState;

// This performs an SPI transaction with the display module; each transaction is a command byte followed by any number of data bytes, surrounded by appropriate #CS manipulation
void sendSpiData(DisplayCommand command, const void *ptr, uint8_t len) {
  const char *p = (const char *) ptr;
  digitalWrite(SPI_CS_PIN, LOW);
  for (int i = len; i; i--) {
    SPI.transfer(*p++);
  }
  digitalWrite(SPI_CS_PIN, HIGH);
}

// Most display commands take a single byte as data; this is a convenience function for those
inline void sendSpiRegister(DisplayCommand command, uint8_t data) {
  sendSpiData(command, &data, 1);
}

// SetText takes a variable length string, so this convenience method finds the length and sends it
inline void sendSpiString(DisplayCommand command, const char *str) {
  sendSpiData(command, str, strlen(str));
}

// SetGlyphData takes a glyph number followed by glyph bitmap data, so this convenience method does the necessary marshalling
void sendSpiGlyph(uint8_t code_point, const uint8_t *rows) {
  uint8_t buf[GLYPH_HEIGHT + 1];
  buf[0] = code_point & 0x7f;
  memcpy(buf + 1, rows, GLYPH_HEIGHT);
  sendSpiData(SetGlyphData, buf, GLYPH_HEIGHT + 1);
}

// Parse a command parameter as either a decimal integer or a hexadecimal number prefixed by "0x"
int parseNumeric(const char *str) {
  return str ? ((str[0] == '0') && (str[1] == 'x')) ? (int) strtol(str + 2, NULL, 16) : atoi(str) : 0;
}

// This processes commands received over the serial pins
inline void handleSerialLine(char *ln) {
  uint8_t n, i, j, k;
  uint8_t *p;
  const char *cmd = strtok(ln, COMMAND_DELIMITERS);
  if (!strcmp_P(cmd, PSTR("led"))) {                    // led <n> <duty-cycle>
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    n = cmd ? parseNumeric(cmd) : 0;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    ledDim[n % LED_COUNT] = cmd ? parseNumeric(cmd) : 0;
    flash.getData()->leds.animation = AnimationStopped;
  } else if (!strcmp_P(cmd, PSTR("random"))) {          // random [<probability-per-led-per-frame> [<decay-per-frame> [<framerate-ms>]]]
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.random.probability = cmd ? parseNumeric(cmd) : 16000;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.random.decay = cmd ? parseNumeric(cmd) - 1 : 0;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.random.frameRate = cmd ? parseNumeric(cmd) / 4 : 1;
    flash.getData()->leds.animation = AnimateRandom;
    animationState.nextFrame = millis();
  } else if (!strcmp_P(cmd, PSTR("rotate"))) {          // rotate [<steps-per-frame-x256-signed> [<length-x256> [<frame-rate-ms>]]]
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.rotate.stepsPerFrame = cmd ? parseNumeric(cmd) : 4;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.rotate.pulseLength = cmd ? parseNumeric(cmd) : 512;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.rotate.frameRate = cmd ? parseNumeric(cmd) / 4 : 1;
    flash.getData()->leds.animation = AnimateRotate;
    animationState.nextFrame = millis();
  } else if (!strcmp_P(cmd, PSTR("double-rotate"))) {   // double-rotate [<steps-per-frame-x256-signed> [<length-x256> [<frame-rate-ms>]]]
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.doubleRotate.stepsPerFrame = cmd ? parseNumeric(cmd) : 4;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.doubleRotate.pulseLength = cmd ? parseNumeric(cmd) : 256;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    flash.getData()->leds.doubleRotate.frameRate = cmd ? parseNumeric(cmd) / 4 : 1;
    flash.getData()->leds.animation = AnimateDoubleRotate;
    animationState.nextFrame = millis();
  } else if (!strcmp_P(cmd, PSTR("cycle"))) {           // cycle [<delay-ms>]
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    if (cmd) {
      flash.getData()->leds.cycleRate = parseNumeric(cmd);
    }
    flash.getData()->leds.animation = CycleInitial;
    animationState.nextAnimation = millis();
  } else if (!strcmp_P(cmd, PSTR("shuffle"))) {         // shuffle [<delay-ms>]
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    if (cmd) {
      flash.getData()->leds.shuffleRate = parseNumeric(cmd);
    }
    flash.getData()->leds.animation = ShuffleInitial;
    animationState.nextAnimation = millis();
  } else if (!strcmp_P(cmd, PSTR("save"))) {            // save
    flash.save();
  } else if (!strcmp_P(cmd, PSTR("text"))) {            // text <display-line>
    cmd = strtok(NULL, "");
    if (!cmd) {
      cmd = "";
    }
    strncpy(flash.getData()->disp.text, cmd, TEXT_BUFFER_SIZE);
    sendSpiString(SetText, flash.getData()->disp.text);
  } else if (!strcmp_P(cmd, PSTR("text-block"))) {      // text-block <n> \n <text-line> \n ...
    textBlockLines = parseNumeric(strtok(NULL, COMMAND_DELIMITERS));
    textBlockPtr = 0;
  } else if (!strcmp_P(cmd, PSTR("glyph-pitch"))) {     // glyph-pitch <horizontal> [<vertical>]
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    n = cmd ? parseNumeric(cmd) : 0;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    n = DisplayFormatGlyphPitch(n, cmd ? parseNumeric(cmd) : 0);
    flash.getData()->disp.glyphPitch = n;
    sendSpiRegister(SetGlyphPitch, n);
  } else if (!strcmp_P(cmd, PSTR("display-dim"))) {     // display-dim <duty-cycle>
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    n = DisplayFormatDimming(cmd ? parseNumeric(cmd) : 255);
    flash.getData()->disp.dim = n;
    sendSpiRegister(SetDimming, n);
  } else if (!strcmp_P(cmd, PSTR("display-frame"))) {   // display-frame <ms> <horizontal> [<vertical>]
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    n = DisplayFormatFrameRate(cmd ? parseNumeric(cmd) : 256);
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    i = cmd ? parseNumeric(cmd) : 0;
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    j = cmd ? parseNumeric(cmd) : 0;
    k = DisplayFormatFrameAdvance(i, j);
    flash.getData()->disp.frameAdvance = k;
    flash.getData()->disp.frameRate = n;
    sendSpiRegister(SetFrameAdvance, k);
    sendSpiRegister(SetFrameRate, n);
  } else if (!strcmp_P(cmd, PSTR("save-display"))) {    // save-display
    flash.saveDisplay();
  } else if (!strcmp_P(cmd, PSTR("glyph"))) {           // glyph ( <n> | '<char>' ) <row-1> <row-2> <row-3> <row-4> <row-5>
    cmd = strtok(NULL, COMMAND_DELIMITERS);
    if (cmd) {
      if ((cmd[0] == '\'') || (cmd[0] == '\"')) {
        // Glyph number is given as a character
        if (cmd[1]) {
          // Quoted character is included in the token
          n = cmd[1];
        } else {
          // Token does not include the quoted character; assume the quoted character is a single space and eat a token for the closing quote (kind of a hack...)
          n = ' ';
          strtok(NULL, COMMAND_DELIMITERS);
        }
      } else {
        // Glyph number is given as an integer
        n = parseNumeric(cmd);
      }
      p = flash.getData()->glyphs[n % GLYPH_COUNT].rows;
      for (i = 0; i < GLYPH_HEIGHT; i++) {
        cmd = strtok(NULL, COMMAND_DELIMITERS);
        p[i] = DisplayFormatGlyphRow(cmd ? parseNumeric(cmd) : 0);
      }
      sendSpiGlyph(n, p);
    }
  } else if (!strcmp_P(cmd, PSTR("save-glyphs"))) {     // save-glyphs
    flash.saveGlyphs();
  }
}

void setup() {
  // LED outputs (these will be PDM outputs)
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PIN(i), OUTPUT);
    ledDim[i] = 0;
    ledPdm[i] = 0;
  }
  
  // Serial control connection on RX and TX at 115200 8N1; see below for syntax
  // NOTE: serial writes should have a write buffer of 32 to 64 bytes?
  Serial.begin(115200);
  Serial.print(SERIAL_PROMPT);
  serialLine[RX_BUF_LEN] = 0;

  // SPI with #CS on digital 10
  SPI.begin();
  pinMode(SPI_CS_PIN, OUTPUT);
  digitalWrite(SPI_CS_PIN, HIGH);

  // Load display module with values from EEPROM
  sendSpiString(SetText, flash.getData()->disp.text);
  sendSpiRegister(SetGlyphPitch, flash.getData()->disp.glyphPitch);
  sendSpiRegister(SetFrameAdvance, flash.getData()->disp.frameAdvance);
  sendSpiRegister(SetFrameRate, flash.getData()->disp.frameRate);
  sendSpiRegister(SetDimming, flash.getData()->disp.dim);
  for (int i = 0; i < GLYPH_COUNT; i++) {
    sendSpiGlyph(i, flash.getData()->glyphs[i].rows);
  }

  // State initialization
  animationState.nextFrame = millis();
  animationState.nextAnimation = millis();
  animationState.rotatePosition = 0;
}

// Set all LEDs to off (this is also used as the first step in drawing an animation in multiple parts)
void clearLeds() {
  for (int i = 0; i < LED_COUNT; i++) {
    ledDim[i] = 0;
  }
}

// Increments (or decrements) the current rotation position by the given amount, keeping it within the range of valid positions
void incrementRotateAnimation(int16_t steps) {
  animationState.rotatePosition += steps;
  while (animationState.rotatePosition >= MAX_ROTATION) {
    animationState.rotatePosition -= MAX_ROTATION;
  }
  while (animationState.rotatePosition < 0) {
    animationState.rotatePosition += MAX_ROTATION;
  }
}

// Draws one pulse of a rotate animation (this is called once for Rotate, twice for DoubleRotate)
void drawRotateAnimation(int16_t rotatePosition, uint16_t pulseLength) {
  uint8_t i, v;
  uint16_t p = rotatePosition;
  uint16_t l = pulseLength;
  if (p >= MAX_ROTATION) {
    p -= MAX_ROTATION;
  }
  // Antialias starting pixel...
  i = p / 256;
  v = 0 - (p % 256);
  // Draw pixels until length is used
  while (l) {
    if (v > l) {
      v = l;
    }
    ledDim[i++] = v;
    i %= LED_COUNT;
    l -= v;
    v = 255;
  }
}

// Handles animation changes and frame advances
void doAnimation() {
  struct FlashLeds *leds = &(flash.getData()->leds);
  enum AnimationState state = leds->animation;

  // Check for change to another animation
  while (isChangingAnimation(state) && (animationState.nextAnimation <= millis())) {
    if (isCycleAnimation(state)) {
      state = leds->animation = nextCycleAnimation(state);
      animationState.nextFrame = millis();
      animationState.nextAnimation += leds->cycleRate;
    } else if (isShuffleAnimation(state)) {
      state = leds->animation = nextShuffleAnimation(state);
      animationState.nextFrame = millis();
      animationState.nextAnimation += leds->shuffleRate;
    } else {
      state = leds->animation = stopCycleShuffle(state);
    }
  }

  // Check/process next animation frame
  while ((state != AnimationStopped) && (animationState.nextFrame <= millis())) {
    if (isRandomAnimation(state)) {
      for (int i = 0; i < LED_COUNT; i++) {
        if (random(leds->random.probability) < 16) {
          ledDim[i] = 255;
        } else if (ledDim[i] > leds->random.decay) {
          ledDim[i] -= leds->random.decay;
          if (ledDim[i] > 1) {
            ledDim[i]--;
          } else {
            ledDim[i] = 0;
            ledPdm[i] = 255;
          }
        } else {
          ledDim[i] = 0;
          ledPdm[i] = 255;
        }
      }
      animationState.nextFrame += ((unsigned long) leds->random.frameRate) * 4;
    } else if (isRotateAnimation(state)) {
      incrementRotateAnimation(leds->rotate.stepsPerFrame);
      clearLeds();
      drawRotateAnimation(animationState.rotatePosition, leds->rotate.pulseLength);
      animationState.nextFrame += ((unsigned long) leds->rotate.frameRate) * 4;
    } else if (isDoubleRotateAnimation(state)) {
      incrementRotateAnimation(leds->doubleRotate.stepsPerFrame);
      clearLeds();
      drawRotateAnimation(animationState.rotatePosition, leds->doubleRotate.pulseLength);
      drawRotateAnimation(animationState.rotatePosition + (MAX_ROTATION / 2), leds->doubleRotate.pulseLength);
      animationState.nextFrame += ((unsigned long) leds->doubleRotate.frameRate) * 4;
    } else {
      state = leds->animation = AnimationStopped;
    }
  }
}

void loop() {
  uint8_t d, p;

  // Check for incoming serial data
  while (Serial.available()) {
    d = Serial.read();
    if (d == '\n') {
      serialLine[serialPtr] = 0;
      if (textBlockLines) {
        // If sending a block of text lines, append this line to the display text buffer
        if (textBlockPtr < TEXT_BUFFER_SIZE) {
          // Separate each line with \n (so, add \n before each line except the first)
          if (textBlockPtr) {
            flash.getData()->disp.text[textBlockPtr++] = '\n';
          }
          // Append the text if there is room
          if (textBlockPtr < TEXT_BUFFER_SIZE) {
            strncpy(flash.getData()->disp.text + textBlockPtr, serialLine, TEXT_BUFFER_SIZE - textBlockPtr);
          }
        }
        // If at the end of the block, send the text to the display module
        if (!--textBlockLines) {
          sendSpiString(SetText, flash.getData()->disp.text);
        }
      } else {
        handleSerialLine(serialLine);
      }
      serialPtr = 0;
    } else if (serialPtr < RX_BUF_LEN) {
      serialLine[serialPtr++] = d;
    }
  }

  // Apply PDM to LEDs
  // (this is like PWM, but the LED is on during iterations where the counter overflows, so pulses are more evenly distributed;
  //  this reduces flicker when the loop is slow and/or the dimming value is at the extremes)
  for (int i = 0; i < LED_COUNT; i++) {
    if ((ledPdm[i] += ledDim[i]) <= ledDim[i]) {
      digitalWrite(LED_PIN(i), HIGH);
    } else {
      digitalWrite(LED_PIN(i), LOW);
    }
  }

  // Handle things that need animating
  doAnimation();
}

