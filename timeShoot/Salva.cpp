/*
   This clas manage the eeprom storage
*/

#include "Salva.h"

Salva::Salva() {

  // verify if the EEPROM is set as I want (First and last byte set as Startcode and endcode)
  // if not I set the defaults values
  if (EEPROM.read(MAXEEPROMADDR-1) != startcode || EEPROM.read(MAXEEPROMADDR) != endcode) {

    // Set a marker to recognize if eeprom is set or not
    EEPROM.write(MAXEEPROMADDR-1, startcode);    // scrivo codici iniziali
    EEPROM.write(MAXEEPROMADDR, endcode); // scrivo cidice finale

    // Clear eeprom byte not used
    for (int i = 11; i < MAXEEPROMADDR; i++)
      EEPROM.write(0, i);

    // Set default values
    setPMin(1.0);       // one picture for minutes
    setPMax1(2550);     // max 2550 picture in picture for minutes
    setPEvery(10);      // Set a picture every 10 minutes
    setPMax2(2550);     // max 2550 picture in picture evry x minutes
    setRealTime(120);   // time of real event duration, 120 minutes, two hours
    setVideoTime(10);   // Video time desidered, 10 seconds
    setFrames(25);      // 25 frames for minutes in the video
    setAFTime(1);       // one second to keep AF
    setShoottime(1);    // one second to do the picture
    setLanguage(1);     // Set defalult language, Italian
  }

  else
    eepromrewtite = 0; // the eeprom was not cleaned
}

// if return 0 the eeprom was not creared, else yes
byte Salva::getEepromWrite() {
  return eepromrewtite;
}

// Return the number of Picture for minutes
float Salva::getPMin() {
  // float to permi to have less than a picture for minuts
  static float r;

  r = EEPROM.read(pMinAdd);

  // we can have from 0.1 picture for minutes, one every 10 minutes
  return float(r) / 10;
}

// Picture for minutes
void Salva::setPMin(float v) {
  // verify if the recived value is inside of range
  if (float(v) > 0 && float(v) < 25.5) {
    EEPROM.write(pMinAdd, byte(v * 10));
  }
  // else write a defalult value
  else { // For safety set a picture for minutes
    EEPROM.write(pMinAdd, byte(10));
  }
}

int Salva::getPMax1() {
  return EEPROM.read(pMax1Add) * 10;
}

// max picture 1
void Salva::setPMax1(int v) {
  if (v > 2550) {
    EEPROM.write(pMax1Add, 255);
  }
  else {
    // it is possible to register a value from 0 to 255, so we save the v/10
    EEPROM.write(pMax1Add, byte(v / 10));
  }
}


// Picture every x minutes
int Salva::getPEvery() {
  static int m = EEPROM.read(pEveyAdd);

  if (m < 1) {
    setPEvery(1);
    return 1;
  }
  else
    return m;
}


void Salva::setPEvery(int v) {
  if (v < 0 )
    EEPROM.write(pEveyAdd, 1);
  else if (v > 255)
    EEPROM.write(pEveyAdd, 255);
  else
    EEPROM.write(pEveyAdd, byte(v));
}

int Salva::getPMax2() {
  return EEPROM.read(pEveyAdd);
}

// max picture 2
void Salva::setPMax2(int v) {
  if (v > 2550) {
    EEPROM.write(pMax2Add, 255);
  }
  else {
    // it is possible to register a value from 0 to 255, so we save the v/10
    EEPROM.write(pMax2Add, byte(v / 10));
  }
}

// Real time of event, max 2550 minutes (42 hour and half)
int Salva::getRealTime() {
  return EEPROM.read(realTimeAdd) * 10;
}

// Real time of event
void Salva::setRealTime(int v) {
  if (v > 2550) {
    EEPROM.write(realTimeAdd, 255);
  }
  else {
    // it is possible to register a value from 0 to 255, so we save the v/10
    EEPROM.write(realTimeAdd, byte(v / 10));
  }
}

// Time of desiderated video in seconds
int Salva::getVideoTime() {
  static int v;
  // go to save in int to have a biggest ragne
  EEPROM.get(videoTimeAdd, v);
  return v;
}

// Time video desiderated
void Salva::setVideoTime(int v) {
  EEPROM.put(videoTimeAdd, v);
}

// Number of fram in the viedo
int Salva::getFrames() {
  static byte f;

  f = EEPROM.read(framesAdd);

  // Verify if stored value is in the range, else set  that in the orrect range
  if (f < 10) {
    setFrames(10);
    return 10;
  }
  else if (f > 100) {
    setFrames(100);
    return 100;
  }
  else
    // if value is correctly setted
    return f;
}

// Frames video
void Salva::setFrames(byte v) {
  // verify if the value is in the correct range
  if (v < 10)
    EEPROM.write(framesAdd, 10);
  else if (v > 100)
    EEPROM.write(framesAdd, 100);
  else
    EEPROM.write(framesAdd, v);
}

float Salva::getAFTime() {
  // float to have less than a second for AF time
  static float r;
  r = EEPROM.read(AFTimeAdd);

  // verify if the stored value is inside the range
  if (int (r) > 3 && int (r) <= 40) {
    return r / 10;
  }
  else {
    // if the stored value is out of range
    setAFTime(1.0);
    return 1.0;
  }
}

// time for AF
void Salva::setAFTime(float v) {
  // vrify if the value is in the correct ragne
  if (v > 0.3 && v <= 4.0) {
    EEPROM.write(AFTimeAdd, byte(v * 10));
  }
  else { // For safety set a picture for minutes
    EEPROM.write(AFTimeAdd, byte(10));
  }
}

float Salva::getShoottime() {
  static float r;
  r = EEPROM.read(shootTimeAdd);

  if (r > 3.0 && r <= 40.0) {
    return r / 10;
  }
  else { // For safety set a picture for minutes
    setShoottime(10);
    return 1.0;
  }
}

// Time of shoot
void Salva::setShoottime(float v) {
  // verify if the stored value is in the range
  if (v > 0.3 && v <= 4) {
    EEPROM.write(shootTimeAdd, byte(v * 10));
  }
  else { // For safety set a picture for minutes
    EEPROM.write(shootTimeAdd, byte(10));
  }
}

int Salva::getLanguage() {
  static byte l = EEPROM.read(languageAdd);

  // For now I have only two languages
  if (l > 0 && l < LANGUAGES)
    return l;
  else {
    setLanguage(1);
    return 1;
  }
}

// Language
void Salva::setLanguage(byte v) {
  // For now I have only two languages
  if (v > 0 && v < LANGUAGES )
    EEPROM.write(languageAdd, v);
  else {
    EEPROM.write(languageAdd, 1);
  }
}
