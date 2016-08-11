/*
 * display.ino - Display module sketch
 * Charles Lehman - 2016-07-24
 * 
 * The first 8 columns are on digital 0-7 (active high)
 * The next 6 columns are on digital 14-19, also known as analog 0-5 (active high)
 * Digital 8-9 control a shift register that selects the current row, shifting from top to bottom
 * The shift register data line is on digital 8 (row select is active high)
 * The shift register clock line is on digital 9 (data is sampled on the rising edge)
 * Receives control commands over SPI with default hardware MISO/MOSI/SCK/CS pins
 */

//FIXME: SS is PCINT2 and should really be set up to synchronize the SPI state using the PC interrupts

#include <SPI.h>
#include "Arduino.h"
#include "DisplayProtocol.h"

// This pin is polled frequently to synchronize on transaction boundaries, since there is no interrupt for #CS
const int SPI_CS_PIN = 10;

// Column outputs are in two banks of consecutive pins, starting from the left and with ascending pin numbers moving to the right
const int DISPLAY_COLS_A = 8;
const int DISPLAY_COLS_B = 6;
const int DISPLAY_COLS = 14;
#define ColumnPinA(i) (i)
#define ColumnPinB(i) (14 + (i))
#define ColumnPortA PORTD
#define ColumnPortB PORTC
#define portWrite(p,v) (p) = (v)

// Rows are accessed via the shift register
const int SHIFT_REGISTER_DATA = 8;
const int SHIFT_REGISTER_CLOCK = 9;
const int DISPLAY_ROWS = 5;

// NOTE: These are volatile because the ISR updates them; they should be cached into a local variable for atomic operations
volatile uint8_t glyphPitch = 0;
volatile uint8_t frameAdvance = 0;
volatile uint8_t frameRate = 0;
volatile uint8_t dimming = 0;

// This controls custom display glyphs
struct FlashGlyph {
  uint8_t rows[GLYPH_HEIGHT];
};
volatile struct FlashGlyph glyphs[GLYPH_COUNT];

// Text to display
volatile char text[TEXT_BUFFER_SIZE];

// SPI slave state
volatile uint8_t spiState = 0;
enum DisplayCommand spiCommand = GetNoop;
uint8_t spiGlyphIdx = 0;
#define SPI_LAST_BYTE 255

// Cached text info
#define MAX_LINES 32
#define LINE_NOT_FOUND 255
uint8_t textLineOffsets[MAX_LINES];
uint8_t textColumnCount = 0;
uint8_t textLineCount = 0;
int16_t textWidth = 0;
int16_t textHeight = 0;

// Text display state
unsigned long nextFrame = 0;
int16_t offset_x = 0;
int16_t offset_y = 0;
uint8_t dimPdm = 0;
uint8_t displayRow = 0;
volatile bool reindex = false;

// Row update rate and dimming
unsigned long lastUpdate = 0;
bool updateDark = false;

// Clears the shift register by shifting in however many LOW values as there are rows
void clearShiftRegister() {
  digitalWrite(SHIFT_REGISTER_DATA, LOW);
  for (int i = DISPLAY_ROWS; i; i--) {
    digitalWrite(SHIFT_REGISTER_CLOCK, LOW);
    digitalWrite(SHIFT_REGISTER_CLOCK, HIGH);
  }
  displayRow = 0;
}

void setup() {
  // Load default text and glyphs from table in program memory
  strcpy_P((char *)text, DEFAULT_TEXT);
  reindex = true;
  memcpy_P((void *)glyphs, DEFAULT_GLYPHS, sizeof(DEFAULT_GLYPHS));

  // SPI slave setup (requires some direct access to AVR registers)
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  SPDR = 0;

  // Set pin mode on column outputs
  for (int i = 0; i < DISPLAY_COLS_A; i++) {
    pinMode(ColumnPinA(i), OUTPUT);
    digitalWrite(ColumnPinA(i), LOW);
  }
  for (int i = 0; i < DISPLAY_COLS_B; i++) {
    pinMode(ColumnPinB(i), OUTPUT);
    digitalWrite(ColumnPinB(i), LOW);
  }

  // Row control setup
  pinMode(SHIFT_REGISTER_DATA, OUTPUT);
  pinMode(SHIFT_REGISTER_CLOCK, OUTPUT);
  clearShiftRegister();

  // Animation state initial values
  nextFrame = millis();
  offset_x = 0;
  offset_y = 0;
  dimPdm = 0;
}

// Handle incomping SPI data; this is handled in the ISR because the response needs to be loaded into SPDR before the master starts clocking the next byte
ISR (SPI_STC_vect) {
  uint8_t d = SPDR;
  // Handle setter commands: store the incoming data byte into the appropriate configuration variable
  if (spiState) {
    if (spiState == SPI_LAST_BYTE) {
      spiState = 0;
    } else if (spiCommand == SetText) {
      text[spiState++ - 1] = d;
      if (!d) {
        spiState = 0;
        reindex = true;
      }
    } else if (spiCommand == SetGlyphPitch) {
      glyphPitch = d;
      spiState = 0;
    } else if (spiCommand == SetFrameAdvance) {
      frameAdvance = d;
      spiState = 0;
    } else if (spiCommand == SetFrameRate) {
      frameRate = d;
      spiState = 0;
    } else if (spiCommand == SetDimming) {
      dimming = d;
      if (!d) {
        dimPdm = 255;
      }
      spiState = 0;
    } else if (spiCommand == SetGlyphData) {
      if (spiState == 1) {
        spiGlyphIdx = d;
        spiState++;
      } else {
        glyphs[spiGlyphIdx].rows[spiState++ - 2] = d;
        if (spiState >= GLYPH_HEIGHT + 2) {
          spiState = 0;
        }
      }
    }
  } else {
    // First byte of a command: store the command and set the state appropriately
    spiCommand = (enum DisplayCommand) d;
    spiState = ((spiCommand == GetNoop) || (spiCommand == SetNoop)) ? 0 : 1;
  }
  // Handle getter commands: load the appropriate configuration variable into the SPI data register
  if (spiState) {
    if (spiCommand == GetText) {
      // NOTE: spiState is uint8_t and TEXT_BUFFER_SIZE is 256, so this buffer can never overflow, and actually the compiler complains about comparisons that are out of range
      //SPDR = (spiState < TEXT_BUFFER_SIZE) ? text[spiState] : 0;
      SPDR = d = text[spiState++ - 1];
      // If this is a null terminator, reset the SPI state on the next iteration
      if (!d) {
        spiState = SPI_LAST_BYTE;
      }
    } else if (spiCommand == GetGlyphPitch) {
      SPDR = glyphPitch;
      spiState = SPI_LAST_BYTE;
    } else if (spiCommand == GetFrameAdvance) {
      SPDR = frameAdvance;
      spiState = SPI_LAST_BYTE;
    } else if (spiCommand == GetFrameRate) {
      SPDR = frameRate;
      spiState = SPI_LAST_BYTE;
    } else if (spiCommand == GetDimming) {
      SPDR = dimming;
      spiState = SPI_LAST_BYTE;
    } else if (spiCommand == GetGlyphData) {
      if (spiState > 1) {
        SPDR = glyphs[spiGlyphIdx].rows[spiState++ - 2];
        if (spiState >= GLYPH_HEIGHT + 2) {
          spiState = SPI_LAST_BYTE;
        }
      }
    }
  }
}

// Determine output bits
inline uint8_t getOutputBits(uint8_t glyphRow, uint8_t cols, uint8_t &textIndex, uint8_t &row, uint8_t &glyphCol, int16_t &x, uint8_t rowStartIndex) {
  uint8_t bits, mask;
  uint8_t pitch = DisplayParseGlyphPitchX(glyphPitch);

  bits = 0;
  mask = 1;
  for (int i = cols; i; i--) {
    if (row & 1) {
      bits |= mask;
    }
    row >>= 1;
    mask <<= 1;
    x++;
    glyphCol++;
    if (glyphCol >= pitch) {
      glyphCol = 0;
      if (x >= textWidth) {
        x = 0;
        textIndex = rowStartIndex;
      } else if (text[textIndex] && (text[textIndex] != '\n')) {
        textIndex++;
      }
      row = DisplayParseGlyphRow(glyphs[text[textIndex % GLYPH_COUNT]].rows[glyphRow]);
    }
  }

  return bits;
}

// Moves to the next row on the display
void updateDisplay() {
  int16_t y, x;
  uint8_t lineIndex, glyphRow, pitch, colIndex, glyphCol, textIndex;
  uint8_t row, mask, bitsA, bitsB;

  // Find the text row and glyph offset for this display row
  y = offset_y + displayRow;
  while (y >= textHeight) {
    y -= textHeight;
  }
  pitch = DisplayParseGlyphPitchY(glyphPitch);
  lineIndex = y / pitch;
  glyphRow = y % pitch;

  // Find text position and glyph offset for the first column
  x = offset_x;
  while (x >= textWidth) {
    x -= textWidth;
  }
  pitch = DisplayParseGlyphPitchX(glyphPitch);
  colIndex = x / pitch;
  glyphCol = x % pitch;
  textIndex = textLineOffsets[lineIndex];
  for (int i = colIndex; i; i--) {
    if (text[textIndex] && (text[textIndex] != '\n')) {
      textIndex++;
    }
  }

  // Determine output bits
  row = DisplayParseGlyphRow(glyphs[text[textIndex % GLYPH_COUNT]].rows[glyphRow]);
  row >>= glyphCol;
  bitsA = getOutputBits(glyphRow, DISPLAY_COLS_A, textIndex, row, glyphCol, x, textLineOffsets[lineIndex]);
  bitsB = getOutputBits(glyphRow, DISPLAY_COLS_B, textIndex, row, glyphCol, x, textLineOffsets[lineIndex]);

  // Apply PDM to handle dimming (the code above is executed whether or not the result is used in order to maintain consistent loop timing)
  if (!displayRow) {
    updateDark = ((dimPdm += dimming) > dimming);
  }
  if (updateDark) {
    bitsA = 0;
    bitsB = 0;
  }

  // Shift to the next row and set the column outputs
  // (data will be displayed on the wrong row for the instant between raising the clock signal and setting the column outputs;
  //  portWrite, defined above, is used instead of digitalWrite because it sets all pins on a port in one operation)
  digitalWrite(SHIFT_REGISTER_DATA, displayRow ? LOW : HIGH);
  digitalWrite(SHIFT_REGISTER_CLOCK, LOW);
  digitalWrite(SHIFT_REGISTER_CLOCK, HIGH);
  portWrite(ColumnPortA, bitsA);
  portWrite(ColumnPortB, bitsB);
  displayRow++;
  while (displayRow >= DISPLAY_ROWS) {
    displayRow -= DISPLAY_ROWS;
  }
}

void loop() {
  int t;

  // No interrupt when select goes high, so keep checking and hope it doesn't go unnoticed
  if (digitalRead(SPI_CS_PIN) == HIGH) {
    spiState = 0;
  }

  // If text buffer has been modified, it needs to be reindexed
  if (reindex) {
    reindex = false;
    textLineCount = 0;
    for (int i = 0; text[i]; i++) {
      if ((text[i] == '\n') && (textLineCount < MAX_LINES)) {
        t = textLineCount ? i - textLineOffsets[textLineCount - 1] - 1 : i;
        if (t > textColumnCount) {
          textColumnCount = t;
        }
        textLineOffsets[textLineCount++] = i;
      }
    }
    for (int i = textLineCount; i < MAX_LINES; i++) {
      textLineOffsets[i] = LINE_NOT_FOUND;
    }
    textWidth = textColumnCount * (int16_t)DisplayParseGlyphPitchX(glyphPitch);
    textHeight = textLineCount * (int16_t)DisplayParseGlyphPitchY(glyphPitch);
  }

  // Update display
  if (lastUpdate != millis()) {
    lastUpdate = millis();
    updateDisplay();
  }

  // Perform frame advance and loopback
  while (frameAdvance && (nextFrame <= millis())) {
    offset_x += DisplayParseFrameAdvanceX(frameAdvance);
    while (offset_x < 0) {
      offset_x += textWidth;
    }
    while (offset_x >= textWidth) {
      offset_x -= textWidth;
    }
    offset_y += DisplayParseFrameAdvanceY(frameAdvance);
    while (offset_y < 0) {
      offset_y += textHeight;
    }
    while (offset_y >= textHeight) {
      offset_y -= textHeight;
    }
    nextFrame += ((unsigned long) frameRate) * 4;
  }
}

