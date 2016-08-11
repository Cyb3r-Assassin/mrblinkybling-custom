/*
 * FlashData.cpp - Configuration and EEPROM accessors
 * Charles Lehman - 2016-07-24
 */

#include "FlashData.h"

#define FLASH_MAGIC 0x5a5a
#define FLASH_VERSION 0x0001
#define FLASH_ADDRESS 0
#define FLASH_LEDS_ADDRESS ((FLASH_ADDRESS) + sizeof(uint8_t))
#define FLASH_DISPLAY_ADDRESS ((FLASH_LEDS_ADDRESS) + sizeof(struct FlashLeds))
#define FLASH_GLYPHS_ADDRESS ((FLASH_DISPLAY_ADDRESS) + sizeof(struct FlashDisplay))
#define FLASH_GLYPH_ADDRESS(i) ((FLASH_GLYPHS_ADDRESS) + (sizeof(struct FlashGlyph) * i))

FlashData::FlashData() {
  EEPROM.get(FLASH_ADDRESS, _ram);
  // If the magic value isn't correct, populate with default values
  if (_ram.magic != FLASH_MAGIC || _ram.version != FLASH_VERSION) {
    _ram.leds.random.probability = 12000;
    _ram.leds.random.decay = 0;
    _ram.leds.random.frameRate = 1;
    _ram.leds.rotate.stepsPerFrame = 4;
    _ram.leds.rotate.pulseLength = 512;
    _ram.leds.rotate.frameRate = 1;
    _ram.leds.doubleRotate.stepsPerFrame = 4;
    _ram.leds.doubleRotate.pulseLength = 256;
    _ram.leds.doubleRotate.frameRate = 1;
    _ram.leds.cycleRate = 8000;
    _ram.leds.shuffleRate = 8000;
    _ram.leds.animation = ShuffleRandom;
    _ram.disp.glyphPitch = DisplayFormatGlyphPitch(6, 6);
    _ram.disp.dim = DisplayFormatDimming(255);
    _ram.disp.frameAdvance = DisplayFormatFrameAdvance(1, 0);
    _ram.disp.frameRate = DisplayFormatFrameRate(256);
    strcpy_P(_ram.disp.text, DEFAULT_TEXT);
    memcpy_P(_ram.glyphs, DEFAULT_GLYPHS, sizeof(DEFAULT_GLYPHS));
  }
}

struct FlashFormat *FlashData::getData() {
  return &_ram;
}

void FlashData::save() {
  if (_ram.magic == FLASH_MAGIC && _ram.version == FLASH_VERSION) {
    EEPROM.put(FLASH_LEDS_ADDRESS, _ram.leds);
  } else {
    saveAll();
  }
}

void FlashData::saveDisplay() {
  if (_ram.magic == FLASH_MAGIC && _ram.version == FLASH_VERSION) {
    EEPROM.put(FLASH_DISPLAY_ADDRESS, _ram.disp);
  } else {
    saveAll();
  }
}

void FlashData::saveGlyphs() {
  if (_ram.magic == FLASH_MAGIC && _ram.version == FLASH_VERSION) {
    EEPROM.put(FLASH_GLYPHS_ADDRESS, _ram.glyphs);
  } else {
    saveAll();
  }
}

void FlashData::saveAll() {
  _ram.magic = FLASH_MAGIC;
  _ram.version = FLASH_VERSION;
  EEPROM.put(FLASH_ADDRESS, _ram);
}

