#include "Salva.h"

Salva::Salva(){

  // Ff eeprom not set as I want I clear it and set default values
  if (EEPROM.read(0) != startcode && EEPROM.read(MAXEEPROMADDR) != endcode){
    
    // Clear eeprom
    for(int i = 1; i < MAXEEPROMADDR; i++)
      EEPROM.write(0, i);

    // Set a marker to recognize if eeprom is set or not
    EEPROM.write(0, startcode);    // scrivo codici iniziali
    EEPROM.write(MAXEEPROMADDR, endcode); // scrivo cidice finale

      // Set default values
    setPMin(1.0);
    setPMax1(2550);
    setPMax2(2550);
    setRealTime(120);
    setVideoTime(10);
    setFrames(25);
    setAFTime(1);
    setShoottime(1);
    setLanguage(1);
  }

}


float Salva::getPMin(){
  static float r;

  r = EEPROM.read(pMinAdd);

  return float(r)/10;
}

int Salva::getPMax1(){
  return EEPROM.read(pMax1Add)*10;
}

int Salva::getPMax2(){
  return EEPROM.read(pMax2Add)*10;
}

int Salva::getRealTime(){
  return EEPROM.read(realTimeAdd)*10;
}

int Salva::getVideoTime(){
  static int v;
  EEPROM.get(videoTimeAdd, v);
  return v;
}

byte Salva::getFrames(){
  return EEPROM.read(framesAdd);
}

float Salva::getAFTime(){
  static float r;
  r = EEPROM.read(AFTimeAdd);

  return r/10;
} 
float Salva::getShoottime(){
  static float r;
  r = EEPROM.read(shootTimeAdd);

  return r/10;
}

byte Salva::getLanguage(){
  return EEPROM.read(languageAdd);
}

// Picture for minutes
void Salva::setPMin(float v){

  if (float(v) > 0 && float(v) < 25){
    EEPROM.write(pMinAdd, byte(v*10));
  }
  else{ // For safety set a picture for minutes
    EEPROM.write(pMinAdd, byte(10));
  }

}

// max picture 1
void Salva::setPMax1(int v){
  if (v > 2550){
    EEPROM.write(pMax1Add, 255);
  }
  else {
    EEPROM.write(pMax1Add, byte(v/10));
  }
}

// max picture 2
void Salva::setPMax2(int v){
  if (v > 2550){
    EEPROM.write(pMax2Add, 255);
  }
  else {
    EEPROM.write(pMax2Add, byte(v/10));
  }
}

// real time of event
void Salva::setRealTime(int v){
  if (v > 2550){
    EEPROM.write(realTimeAdd, 255);
  }
  else {
    EEPROM.write(realTimeAdd, byte(v/10));
  }
}

// Time video desiderated
void Salva::setVideoTime(int v){
  EEPROM.put(videoTimeAdd, v);
}

// Frames video
void Salva::setFrames(byte v){
  if (v < 10)
    EEPROM.write(framesAdd, 10);
  else if (v > 100)
    EEPROM.write(framesAdd, 100);
  else
    EEPROM.write(framesAdd, v);
}

// time for AF
void Salva::setAFTime(float v){

  if (v > 0.3 && v <= 2){
    EEPROM.write(AFTimeAdd, byte(v*10));
  }
  else{ // For safety set a picture for minutes
    EEPROM.write(AFTimeAdd, byte(10));
  }
}

// Time of shoot
void Salva::setShoottime(float v){
  if (v > 0.3 && v <= 2){
    EEPROM.write(shootTimeAdd, byte(v*10));
  }
  else{ // For safety set a picture for minutes
    EEPROM.write(shootTimeAdd, byte(10));
  }
}

// Language
void Salva::setLanguage(byte v){
  EEPROM.write(languageAdd, v);
}


