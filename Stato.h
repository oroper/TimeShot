#ifndef Stato_h
#define Stato_h

#include "Arduino.h"

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
#define LANGUAGES 2

class Stato{

  typedef struct Screen {
    char first[4];
    char second[4];
  };

public:
  Stato();
  void su();
  void giu();
  byte getStato();

  void confirm();
  byte getCursor();
  String getPrint(int);

  void stato1();
  void stato2_1();
  void stato2_2();
  void stato2_3();
  void stato2_4();
  void stato2_5();
  void stato3();

private:

  Screen screen = {"ER","ER"};

  int stato;
  byte cursore;
  byte options;

  void azzCursore();
  void setStato(int);
  
  String getPrintS1(int);
  String getPrintS21(int);

  byte getOptions();

};

#endif



