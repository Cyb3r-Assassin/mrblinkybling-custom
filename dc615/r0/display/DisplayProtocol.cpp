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

  DisplayFormatGlyphBits(0, 0, 1, 0, 0),   // +    0x2b
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(1, 1, 1, 1, 1),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),

  DisplayFormatGlyphBits(0, 0, 0, 0, 0),   // ,    0x2c
  DisplayFormatGlyphBits(0, 0, 0, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 0, 1, 0, 0),
  DisplayFormatGlyphBits(0, 1, 0, 0, 0),

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

const uint8_t DEFAULT_KERNING[GLYPH_COUNT] PROGMEM = {
  DisplayFormatKerning(0, 0),   // nul  0x00
  DisplayFormatKerning(0, 0),   // soh  0x01
  DisplayFormatKerning(0, 0),   // stx  0x02
  DisplayFormatKerning(0, 0),   // etx  0x03
  DisplayFormatKerning(0, 0),   // eot  0x04
  DisplayFormatKerning(0, 0),   // enq  0x05
  DisplayFormatKerning(0, 0),   // ack  0x06
  DisplayFormatKerning(0, 0),   // bel  0x07
  DisplayFormatKerning(0, 0),   // bs   0x08
  DisplayFormatKerning(0, 0),   // tab  0x09
  DisplayFormatKerning(0, 0),   // lf   0x0a
  DisplayFormatKerning(0, 0),   // vt   0x0b
  DisplayFormatKerning(0, 0),   // ff   0x0c
  DisplayFormatKerning(0, 0),   // cr   0x0d
  DisplayFormatKerning(0, 0),   // so   0x0e
  DisplayFormatKerning(0, 0),   // si   0x0f
  DisplayFormatKerning(0, 0),   // dle  0x10
  DisplayFormatKerning(0, 0),   // dc1  0x11
  DisplayFormatKerning(0, 0),   // dc2  0x12
  DisplayFormatKerning(0, 0),   // dc3  0x13
  DisplayFormatKerning(0, 0),   // dc4  0x14
  DisplayFormatKerning(0, 0),   // nak  0x15
  DisplayFormatKerning(0, 0),   // syn  0x16
  DisplayFormatKerning(0, 0),   // etb  0x17
  DisplayFormatKerning(0, 0),   // can  0x18
  DisplayFormatKerning(0, 0),   // em   0x19
  DisplayFormatKerning(0, 0),   // sub  0x1a
  DisplayFormatKerning(0, 0),   // esc  0x1b
  DisplayFormatKerning(0, 0),   // fs   0x1c
  DisplayFormatKerning(0, 0),   // gs   0x1d
  DisplayFormatKerning(0, 0),   // rs   0x1e
  DisplayFormatKerning(0, 0),   // us   0x1f
  DisplayFormatKerning(0, 0),   //      0x20
  DisplayFormatKerning(2, 2),   // !    0x21
  DisplayFormatKerning(1, 1),   // "    0x22
  DisplayFormatKerning(0, 0),   // #    0x23
  DisplayFormatKerning(0, 0),   // $    0x24
  DisplayFormatKerning(0, 0),   // %    0x25
  DisplayFormatKerning(0, 0),   // &    0x26
  DisplayFormatKerning(2, 2),   // '    0x27
  DisplayFormatKerning(1, 2),   // (    0x28
  DisplayFormatKerning(2, 1),   // )    0x29
  DisplayFormatKerning(0, 0),   // *    0x2a
  DisplayFormatKerning(0, 0),   // +    0x2b
  DisplayFormatKerning(1, 2),   // ,    0x2c
  DisplayFormatKerning(0, 0),   // -    0x2d
  DisplayFormatKerning(2, 2),   // .    0x2e
  DisplayFormatKerning(0, 0),   // /    0x2f
  DisplayFormatKerning(0, 0),   // 0    0x30
  DisplayFormatKerning(1, 1),   // 1    0x31
  DisplayFormatKerning(0, 0),   // 2    0x32
  DisplayFormatKerning(0, 0),   // 3    0x33
  DisplayFormatKerning(0, 0),   // 4    0x34
  DisplayFormatKerning(0, 0),   // 5    0x35
  DisplayFormatKerning(0, 0),   // 6    0x36
  DisplayFormatKerning(0, 0),   // 7    0x37
  DisplayFormatKerning(0, 0),   // 8    0x38
  DisplayFormatKerning(0, 0),   // 9    0x39
  DisplayFormatKerning(2, 2),   // :    0x3a
  DisplayFormatKerning(1, 2),   // ;    0x3b
  DisplayFormatKerning(0, 2),   // <    0x3c
  DisplayFormatKerning(0, 0),   // =    0x3d
  DisplayFormatKerning(2, 0),   // >    0x3e
  DisplayFormatKerning(0, 0),   // ?    0x3f
  DisplayFormatKerning(0, 0),   // @    0x40
  DisplayFormatKerning(0, 0),   // A    0x41
  DisplayFormatKerning(0, 0),   // B    0x42
  DisplayFormatKerning(0, 0),   // C    0x43
  DisplayFormatKerning(0, 0),   // D    0x44
  DisplayFormatKerning(0, 0),   // E    0x45
  DisplayFormatKerning(0, 0),   // F    0x46
  DisplayFormatKerning(0, 0),   // G    0x47
  DisplayFormatKerning(0, 0),   // H    0x48
  DisplayFormatKerning(0, 0),   // I    0x49
  DisplayFormatKerning(0, 0),   // J    0x4a
  DisplayFormatKerning(0, 0),   // K    0x4b
  DisplayFormatKerning(0, 0),   // L    0x4c
  DisplayFormatKerning(0, 0),   // M    0x4d
  DisplayFormatKerning(0, 0),   // N    0x4e
  DisplayFormatKerning(0, 0),   // O    0x4f
  DisplayFormatKerning(0, 0),   // P    0x50
  DisplayFormatKerning(0, 0),   // Q    0x51
  DisplayFormatKerning(0, 0),   // R    0x52
  DisplayFormatKerning(0, 0),   // S    0x53
  DisplayFormatKerning(0, 0),   // T    0x54
  DisplayFormatKerning(0, 0),   // U    0x55
  DisplayFormatKerning(0, 0),   // V    0x56
  DisplayFormatKerning(0, 0),   // W    0x57
  DisplayFormatKerning(0, 0),   // X    0x58
  DisplayFormatKerning(0, 0),   // Y    0x59
  DisplayFormatKerning(0, 0),   // Z    0x5a
  DisplayFormatKerning(1, 1),   // [    0x5b
  DisplayFormatKerning(0, 0),   // \    0x5c
  DisplayFormatKerning(1, 1),   // ]    0x5d
  DisplayFormatKerning(1, 1),   // ^    0x5e
  DisplayFormatKerning(0, 0),   // _    0x5f
  DisplayFormatKerning(2, 1),   // `    0x60
  DisplayFormatKerning(0, 0),   // a    0x61
  DisplayFormatKerning(0, 0),   // b    0x62
  DisplayFormatKerning(0, 0),   // c    0x63
  DisplayFormatKerning(0, 0),   // d    0x64
  DisplayFormatKerning(0, 0),   // e    0x65
  DisplayFormatKerning(1, 1),   // f    0x66
  DisplayFormatKerning(0, 0),   // g    0x67
  DisplayFormatKerning(0, 0),   // h    0x68
  DisplayFormatKerning(2, 2),   // i    0x69
  DisplayFormatKerning(0, 2),   // j    0x6a
  DisplayFormatKerning(1, 1),   // k    0x6b
  DisplayFormatKerning(2, 1),   // l    0x6c
  DisplayFormatKerning(0, 0),   // m    0x6d
  DisplayFormatKerning(1, 1),   // n    0x6e
  DisplayFormatKerning(1, 1),   // o    0x6f
  DisplayFormatKerning(1, 1),   // p    0x70
  DisplayFormatKerning(1, 0),   // q    0x71
  DisplayFormatKerning(2, 0),   // r    0x72
  DisplayFormatKerning(1, 1),   // s    0x73
  DisplayFormatKerning(1, 1),   // t    0x74
  DisplayFormatKerning(1, 1),   // u    0x75
  DisplayFormatKerning(1, 1),   // v    0x76
  DisplayFormatKerning(0, 0),   // w    0x77
  DisplayFormatKerning(1, 1),   // x    0x78
  DisplayFormatKerning(1, 1),   // y    0x79
  DisplayFormatKerning(1, 1),   // z    0x7a
  DisplayFormatKerning(0, 2),   // {    0x7b
  DisplayFormatKerning(2, 2),   // |    0x7c
  DisplayFormatKerning(2, 0),   // }    0x7d
  DisplayFormatKerning(0, 0),   // ~    0x7e
  DisplayFormatKerning(1, 1)    // del  0x7f
};

