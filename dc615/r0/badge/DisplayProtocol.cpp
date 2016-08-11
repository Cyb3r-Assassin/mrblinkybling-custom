/*
 * DisplayProtocol.h - Constants for display module
 * Charles Lehman - 2016-07-24
 */

#include "DisplayProtocol.h"

const char DEFAULT_TEXT[] PROGMEM = "dc615.org  ";

const uint8_t DEFAULT_GLYPHS[GLYPH_COUNT * GLYPH_HEIGHT] PROGMEM = {
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // nul  0x00
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 1),   // soh  0x01
  DisplayFormatGlyphBits(0, 1, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // stx  0x02
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // etx  0x03
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // eot  0x04
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // enq  0x05
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // ack  0x06
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // bel  0x07
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // bs   0x08
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // tab  0x09
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // lf   0x0a
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // vt   0x0b
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // ff   0x0c
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // cr   0x0d
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // so   0x0e
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // si   0x0f
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // dle  0x10
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // dc1  0x11
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // dc2  0x12
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // dc3  0x13
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // dc4  0x14
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // nak  0x15
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // syn  0x16
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // etb  0x17
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // can  0x18
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // em   0x19
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // sub  0x1a
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // esc  0x1b
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // fs   0x1c
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // gs   0x1d
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // rs   0x1e
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // us   0x1f
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   //      0x20
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // !    0x21
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 1, 0, 1, 0),   // "    0x22
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 1, 0, 1, 0),   // #    0x23
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 1),   // $    0x24
  DisplayFormatGlyphBits(1, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // %    0x25
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // &    0x26
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // '    0x27
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // (    0x28
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // )    0x29
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(1, 0, 1, 0, 1),   // *    0x2a
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // +    0x2b
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // ,    0x2c
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // -    0x2d
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // .    0x2e
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 1),   // /    0x2f
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // 0    0x30
  DisplayFormatGlyphBits(1, 0, 0, 1, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 1, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // 1    0x31
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // 2    0x32
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 0),   // 3    0x33
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // 4    0x34
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // 5    0x35
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 1),   // 6    0x36
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // 7    0x37
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // 8    0x38
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 1),   // 9    0x39
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // :    0x3a
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // ;    0x3b
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // <    0x3c
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // =    0x3d
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // >    0x3e
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // ?    0x3f
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // @    0x40
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // A    0x41
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 0),   // B    0x42
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 1),   // C    0x43
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 0),   // D    0x44
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // E    0x45
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // F    0x46
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 1),   // G    0x47
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 1, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // H    0x48
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // I    0x49
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // J    0x4a
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // K    0x4b
  DisplayFormatGlyphBits(1, 0, 0, 1, 0),
  DisplayFormatGlyphBits(1, 1, 1, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(1, 0, 0, 0, 0),   // L    0x4c
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // M    0x4d
  DisplayFormatGlyphBits(1, 1, 0, 1, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // N    0x4e
  DisplayFormatGlyphBits(1, 1, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // O    0x4f
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 1, 1, 1, 0),   // P    0x50
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // Q    0x51
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 1, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),

  DisplayFormatGlyphBits(1, 1, 1, 1, 0),   // R    0x52
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(0, 1, 1, 1, 1),   // S    0x53
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // T    0x54
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // U    0x55
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // V    0x56
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // W    0x57
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 1, 0, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // X    0x58
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(1, 0, 0, 0, 1),   // Y    0x59
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(1, 1, 1, 1, 1),   // Z    0x5a
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),

  DisplayFormatGlyphBits(0, 1, 1, 0, 0),   // [    0x5b
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 0),   // \    0x5c
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),

  DisplayFormatGlyphBits(0, 0, 1, 1, 0),   // ]    0x5d
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // ^    0x5e
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // _    0x5f
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // `    0x60
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(1, 1, 1, 1, 0),   // a    0x61
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),

  DisplayFormatGlyphBits(1, 0, 0, 0, 0),   // b    0x62
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // c    0x63
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),

  DisplayFormatGlyphBits(0, 0, 0, 0, 1),   // d    0x64
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // e    0x65
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),

  DisplayFormatGlyphBits(0, 0, 1, 1, 0),   // f    0x66
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 1, 1, 1, 0),   // g    0x67
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(0, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),

  DisplayFormatGlyphBits(1, 0, 0, 0, 0),   // h    0x68
  DisplayFormatGlyphBits(1, 0, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 0),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // i    0x69
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // j    0x6a
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),

  DisplayFormatGlyphBits(0, 1, 0, 0, 0),   // k    0x6b
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // l    0x6c
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // m    0x6d
  DisplayFormatGlyphBits(1, 1, 0, 1, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // n    0x6e
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // o    0x6f
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // p    0x70
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // q    0x71
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 1),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // r    0x72
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 1),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 1, 0),   // s    0x73
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // t    0x74
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // u    0x75
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // v    0x76
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // w    0x77
  DisplayFormatGlyphBits(1, 0, 0, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // x    0x78
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // y    0x79
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // z    0x7a
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 1, 0),
  DisplayFormatGlyphBits(0, 1, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // {    0x7b
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(1, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // |    0x7c
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // }    0x7d
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 1, 1),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // ~    0x7e
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),
  DisplayFormatGlyphBits(1, 0, 1, 0, 1),
  DisplayFormatGlyphBits(0, 0, 0, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // del  0x7f
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 1, 0, 1, 0),
  DisplayFormatGlyphBits(0, 1, 1, 1, 0),
  DisplayFormatGlyphBits(0, 0, 0, 0, 0)
};

