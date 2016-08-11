/*
 * FlashData.h - Structure for the EEPROM data
 * Charles Lehman - 2016-07-24
 */

#ifndef FlashData_h
#define FlashData_h

#include <EEPROM.h>
#include "Arduino.h"
#include "DisplayProtocol.h"

enum AnimationState {
  AnimationStopped = 0x00,
  AnimateRandom = 0x01,
  AnimateRotate = 0x02,
  AnimateDoubleRotate = 0x03,
  CycleInitial = 0x10,
  CycleRandom = 0x11,
  CycleRotate = 0x12,
  CycleDoubleRotate = 0x13,
  ShuffleInitial = 0x20,
  ShuffleRandom = 0x21,
  ShuffleRotate = 0x22,
  ShuffleDoubleRotate = 0x23
};
#define AnimationCount 0x03

#define isChangingAnimation(x) ((x) & 0xf0)
#define isRandomAnimation(x) (((x) & 0x0f) == AnimateRandom)
#define isRotateAnimation(x) (((x) & 0x0f) == AnimateRotate)
#define isDoubleRotateAnimation(x) (((x) & 0x0f) == AnimateDoubleRotate)
#define isCycleAnimation(x) (((x) & 0xf0) == CycleInitial)
#define isShuffleAnimation(x) (((x) & 0xf0) == ShuffleInitial)
#define nextCycleAnimation(x) ((AnimationState) ((((x) & 0x0f) >= AnimationCount) ? CycleRandom : ((x) + 1)))
#define nextShuffleAnimation(x) ((AnimationState) (random(AnimationCount) + ShuffleInitial + 1))
#define stopCycleShuffle(x) ((AnimationState) ((x) & 0x0f))

// This controls the main badge LEDs
struct FlashLeds {
  // Random animation
  struct {
    uint16_t probability;        // probability of any single LED being set to 255 in an animation frame (probability is 16 in x+1)
    uint8_t decay;               // amount to decrement per frame (steps - 1)
    uint8_t frameRate;           // frame advance rate (ms / 4)
  } random;
  // Single rotating pulse animation
  struct {
    int16_t stepsPerFrame;       // signed number of steps it increment per frame (256 steps is one LED)
    uint16_t pulseLength;        // length of illuminated pulse (256 steps is one LED)
    uint8_t frameRate;           // frame advance rate (ms / 4)
  } rotate;
  // Two rotating pulses animation
  struct {
    int16_t stepsPerFrame;       // signed number of steps it increment per frame (256 steps is one LED)
    uint16_t pulseLength;        // length of illuminated pulse (256 steps is one LED)
    uint8_t frameRate;           // frame advance rate (ms / 4)
  } doubleRotate;
  uint16_t cycleRate;            // time to spend in each animation while in cycle mode (ms)
  uint16_t shuffleRate;          // time to spend in each animation while in shuffle mode (ms)
  enum AnimationState animation; // current animation state
};   // ~20 bytes

// This controls the display text and animation
struct FlashDisplay {
  uint8_t glyphPitch;            // spacing for glyphs in display protocol format (see DisplayProtocol.h)
  uint8_t dim;                   // dimming value for all LEDs
  uint8_t frameAdvance;          // pixels to advance each frame in display protocol format (see DisplayProtocol.h)
  uint8_t frameRate;             // frame advance rate (ms / 4)
  char text[TEXT_BUFFER_SIZE];   // text to display (ASCIIZ)
};   // ~260 bytes

// This controls custom display glyphs
struct FlashGlyph {
  uint8_t rows[GLYPH_HEIGHT];
};   // ~640 bytes

// This is a wrapper for the above data
struct FlashFormat {
  uint16_t magic;                // if this is not correctly initialized, the code assumes EEPROM does not contain valid configuration data
  uint16_t version;              // if this is not the correct number, configuration gets reset (future code may choose to convert the configuration)
  struct FlashLeds leds;
  struct FlashDisplay disp;
  struct FlashGlyph glyphs[GLYPH_COUNT];
};   // ~924 bytes

class FlashData {
  public:
  FlashData();
  struct FlashFormat *getData();
  void save();
  void saveDisplay();
  void saveGlyphs();
  void saveAll();
  private:
  struct FlashFormat _ram;
};

#endif

