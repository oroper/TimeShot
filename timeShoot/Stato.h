#ifndef Stato_h
#define Stato_h

#include "Arduino.h"
#include "GlobalVal.h"
#include "Salva.h"

// stato 1:   menu principale          5 opzioni  codifica: 100
// stato 2_1: menu foto al minuto      4 opzioni  codifica: 210
// stato 2_2: menu foto ogni n minuti  4 opzioni  codifica: 220
// stato 2_3: menu foto per video      5 opzioni  codifica: 230
// stato 2_4: menu impostazioni        3 opzioni  codifica: 240
// stato 2_5: menu lingua              lingue + 1 codifica: 250
// stato 3:   schermata running        3 opzioni  codifica: 300

#define S1 100
#define S21 210
#define S22 220
#define S23 230
#define S24 240
#define S25 250
#define S3 300

class Stato{

  Salva salva; // object that rappresents the eeprom information storage

public:
  Stato();
  void su();
  void giu();
  int getStato();

  void confirm();
  byte getCursor();
  String getPrint(int);

  String getValue(int i);
  String getValueS21(int i);
  String getValueS22(int i);
  float getValueF();
  int getValueI();

  String getString(int);

  String getString(float);

  byte getLanguage();
  byte getEepromWrite();

  void stato1();
  void stato2_1();
  void stato2_2();
  void stato2_3();
  void stato2_4();
  void stato2_5();
  void stato3();

private:

  int stato;
  byte cursore;
  byte options;
  byte com = 0;
  int comInt;
  float comFloat;

  void comPrev();
  void comNext();
  String getCommand();

  void command21_1();

  void azzCursore();
  void setStato(int);
  
  String getPrintS1(int);
  String getPrintS21(int);
  String getPrintS22(int);

  byte getOptions();

};

#endif




