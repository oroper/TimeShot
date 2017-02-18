#ifndef Salva_h
#define Salva_h

#include "Arduino.h"
#include <EEPROM.h>
#include "GlobalVal.h"


#define MAXEEPROMADDR E2END

#define pMinAdd 1        // Indirizzo Foto al minuto
#define pMax1Add 2       // Indirizzo Numero massimo di foto in foto al minuto
#define pEveyAdd 3        // Indirizzo Foto al minuto
#define pMax2Add 4       // Indirizzo Numero massimo di foto in foto ogni n min
#define realTimeAdd 5    // Indirizzo Durata dell'evento reale
#define videoTimeAdd 6   // Indirizzo Durata del video che si desidera, in secondi doppio spazio
#define framesAdd 8      // Indirizzo Numero di fotogrammi al secondo che si vogliono per il video
#define AFTimeAdd 9      // Indirizzo Quanto tempo lasciare per la messa a fuoco prima dello scatto
#define shootTimeAdd 10   // Indirizzo Tempo da lasciare per lo scatto
#define languageAdd 11   // Indirizzo Indice della lingua selezionata

class Salva {

  public:
    Salva();                    // Verify the eeprom status and set default values if needed
    float getPMin();            // Picture for minute
    int getPMax1();             // Max mumber of picture for "Picture for minute"
    int getPEvery();            // Pecture every x minutes
    int getPMax2();             // Max mumber of picture for "Picture every x minutes"
    int getRealTime();          // Durata dell'evento reale
    int getVideoTime();         // Durata del video che si desidera
    int getFrames();           // Numero di fotogrammi al secondo che si vogliono per il video
    float getAFTime();          // Quanto tempo lasciare per la messa a fuoco prima dello scatto
    float getShoottime();       // Tempo da lasciare per lo scatto
    int getLanguage();         // Lingua

    byte getEepromWrite();      // restituisce un valore che se è 1 vuol dire che la eeprom è stata resettata

    void setPMin(float);
    void setPMax1(int);
    void setPEvery(int);
    void setPMax2(int);
    void setRealTime(int);
    void setVideoTime(int);
    void setFrames(byte);
    void setAFTime(float);
    void setShoottime(float);
    void setLanguage(byte);

  private:
    const byte startcode = 0b10101010;  // Start vale in eeprom to veryfi if it was inizializzed
    const byte endcode = 0b01010101;    // End vale in eeprom to veryfi if it was inizializzed

    byte eepromrewtite = 0;             // define if eeprom was reset
};

#endif


