/*
 * DisplayProtocol.h - Constants for display module
 * Charles Lehman - 2016-07-24
 */

#ifndef DisplayProtocol_h
#define DisplayProtocol_h

#include "Arduino.h"

#define TEXT_BUFFER_SIZE 256
#define GLYPH_HEIGHT 5
#define GLYPH_COUNT 128

enum DisplayCommand {
  GetNoop = 0x00,
  SetNoop = 0x01,
  GetText = 0x02,
  SetText = 0x03,
  GetGlyphPitch = 0x04,
  SetGlyphPitch = 0x05,
  GetFrameAdvance = 0x06,
  SetFrameAdvance = 0x07,
  GetFrameRate = 0x08,
  SetFrameRate = 0x09,
  GetDimming = 0x0a,
  SetDimming = 0x0b,
  GetGlyphData = 0x0c,
  SetGlyphData = 0x0d,
  Reserved = 0x0e
};

#define DisplayFormatGlyphPitch(x,y) ((((y) & 0x0f) << 4) + ((x) & 0x0f))
#define DisplayFormatFrameAdvance(x,y) ((((y) & 0x0f) << 4) | ((x) & 0x0f))
#define DisplayFormatFrameRate(ms) ((ms) >> 2)
#define DisplayFormatDimming(x) (x)
#define DisplayFormatGlyphRow(x) ((x) | 0x80)
#define DisplayFormatGlyph(a,b,c,d,e) DisplayFormatGlyphRow(a), DisplayFormatGlyphRow(b), DisplayFormatGlyphRow(c), DisplayFormatGlyphRow(d), DisplayFormatGlyphRow(e)
#define DisplayFormatGlyphBits(a,b,c,d,e) ( B100 ## e ## d ## c ## b ## a )

#define DisplayParseGlyphPitchX(n) ((n) & 0x0f)
#define DisplayParseGlyphPitchY(n) ((n) >> 4)
#define DisplayParseFrameAdvanceX(n) (((n) & 0x08) ? -1 - (int8_t)(0x07 & ~(n)) : (int8_t)((n) & 0x07))
#define DisplayParseFrameAdvanceY(n) (((n) & 0x80) ? -1 - (int8_t)(0x07 & ~((n) >> 4)) : (int8_t)((n) >> 4))
#define DisplayParseFrameRate(n) (((uint16_t)(n)) << 2)
#define DisplayParseDimming(n) (n)
#define DisplayParseGlyphRow(x) ((x) & 0x7f)

extern const char DEFAULT_TEXT[] PROGMEM;
extern const uint8_t DEFAULT_GLYPHS[GLYPH_COUNT * GLYPH_HEIGHT] PROGMEM;

#endif

