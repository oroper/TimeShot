#ifndef Boot_h
#define Boot_h

#include "Arduino.h"

static byte v[8] = {
  B00000,
  B00101,
  B00101,
  B00101,
  B00101,
  B00010,
  B00000,
  B00000
};

static byte ee[8] = {
  B00000,
  B01110,
  B01000,
  B01100,
  B01000,
  B01110,
  B00000,
  B00000
};

static byte r[8] = {
  B00000,
  B10000,
  B11100,
  B10100,
  B10000,
  B10001,
  B00000,
  B00000
};

static byte u[8] = {
  B00000,
  B00001,
  B00011,
  B00101,
  B00001,
  B00001,
  B00000,
  B00000
};

static byte z[8] = {
  B00000,
  B00010,
  B00101,
  B00101,
  B00101,
  B10010,
  B00000,
  B00000
};

static byte arrow[8] = {
  B00000,
  B10000,
  B11000,
  B11100,
  B11110,
  B11100,
  B11000,
  B10000
};

#endif

