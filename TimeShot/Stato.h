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
#define S31 310
#define S32 320
#define S33 330

#define S211 211  // Modifica valore foto per minuto
#define S212 212  // Modifica valore foto max1
#define S221 221  // Modifica valore foto ogni
#define S222 222  // Modifica valore foto max2
#define S231 231  // Modifica valroe durata evento
#define S232 232  // Modifica valore durata video
#define S233 233  // Modifica valore fotogrammi
#define S241 241  // Modifica valroe durata AF
#define S242 242  // Modifica valroe scatto

class Stato {

    Salva salva; // object that rappresents the eeprom information storage

  public:
    Stato();
    void su();
    void giu();
    int getStato();

    void confirm();
    byte getCursor();
    int getPrint(int);

    float getValue(int);
    float getStartVal();

    float valSu(float f);
    float valGiu(float f);

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

    void startPPM();    // foto al minuto
    void startPEM();    // foto ogni x minuti
    void startVideo();  // foto per video

    void salvaVal(float);

    float valSu();
    int getPos();

    void setStato(int);

    void scattato();
    boolean  getScattato();

    int getStatoName();
    unsigned int getCount();

    void shooting();
    unsigned int timing();

  private:

    int stato;
    byte cursore;
    byte cursoreOld;
    byte cursoreOld1;
    byte options;
    byte com = 0;
    int comInt;
    float comFloat;

    unsigned int start;   // Time di quando iniziato
    unsigned int last;     // Ultimo scatto
    unsigned int delta;   // ogni quanti milli secondi scattare
    unsigned int count;   // Quante foto sono state fatte
    unsigned int finish;  // quante foto da fare per terminare

    boolean scatta = 0;

    void comPrev();
    void comNext();
    String getCommand();

    void command21_1();

    void azzCursore();


    int getPrintS1(int);
    int getPrintS21(int);
    int getPrintS22(int);
    int getPrintS23(int);
    int getPrintS24(int);
    int getPrintS25(int);

    float getValueS21(int);
    float getValueS22(int);
    float getValueS23(int);
    float getValueS24(int);

    byte getOptions();

};

#endif




