#ifndef Salva_h
#define Salva_h

#include "Arduino.h"
#include <C:\Users\Nevio\Dropbox\timeShoot./EEPROM/EEPROM.h>


#define MAXEEPROMADDR E2END

#define pMinAdd 1        // Indirizzo Foto al minuto
#define pMax1Add 2       // Indirizzo Numero massimo di foto in foto al minuto
#define pMax2Add 3       // Indirizzo Numero massimo di foto in foto ogni n min
#define realTimeAdd 4    // Indirizzo Durata dell'evento reale
#define videoTimeAdd 5   // Indirizzo Durata del video che si desidera, in secondi doppio spazio
#define framesAdd 7      // Indirizzo Numero di fotogrammi al secondo che si vogliono per il video
#define AFTimeAdd 8      // Indirizzo Quanto tempo lasciare per la messa a fuoco prima dello scatto
#define shootTimeAdd 9   // Indirizzo Tempo da lasciare per lo scatto
#define languageAdd 10   // Indirizzo Indice della lingua selezionata

class Salva{

public:
  Salva();
  float getPMin();        // Foto al minuto
  int getPMax1();       // Numero massimo di foto in foto al minuto
  int getPMax2();       // Numero massimo di foto in foto ogni n min
  int getRealTime();    // Durata dell'evento reale
  int getVideoTime();    // Durata del video che si desidera
  byte getFrames();      // Numero di fotogrammi al secondo che si vogliono per il video
  float getAFTime();      // Quanto tempo lasciare per la messa a fuoco prima dello scatto
  float getShoottime();   // Tempo da lasciare per lo scatto
  byte getLanguage();    // Lingua

  void setPMin(float);        // Foto al minuto
  void setPMax1(int);       // Numero massimo di foto in foto al minuto
  void setPMax2(int);       // Numero massimo di foto in foto ogni n min
  void setRealTime(int);    // Durata dell'evento reale
  void setVideoTime(int);    // Durata del video che si desidera
  void setFrames(byte);      // Numero di fotogrammi al secondo che si vogliono per il video
  void setAFTime(float);      // Quanto tempo lasciare per la messa a fuoco prima dello scatto
  void setShoottime(float);   // Tempo da lasciare per lo scatto
  void setLanguage(byte);    // Lingua

private:
  const byte startcode = 0b10101010;
  const byte endcode = 0b01010101;
  /*
  byte fMin;        // Foto al minuto
   byte fMax1;       // Numero massimo di foto in foto al minuto
   byte fMax2;       // Numero massimo di foto in foto ogni n min
   byte durataR;     // Durata dell'evento reale
   int durataV;      // Durata del video che si desidera
   byte fotogrammi;  // Numero di fotogrammi al secondo che si vogliono per il video
   byte durataAF;    // Quanto tempo lasciare per la messa a fuoco prima dello scatto
   byte durataS;     // Tempo da lasciare per lo scatto
   byte lingua;      // Indice della lingua selezionata
   */
};

#endif


