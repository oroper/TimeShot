/*
   This calss mantain the information about the status and the connection between these
*/

#include "Stato.h"

// stato 1: menu principale - 5 opzioni
// stato 2_1: menu foto al minuto - 4 opzioni
// stato 2_2: menu foto ogni n minuti - 4 opzioni
// stato 2_3: menu foto per video - 5 opzioni
// stato 2_4: menu impostazioni - 3 opzioni
// stato 2_5: menu lingua - lingua opzioni + 1
// stato 3: schermata running - 3 opzioni
// stato 4: Fine scatti

// inizialize the object
Stato::Stato() {

  // Start from first menu
  stato = S1;

  // cursor on first voice
  cursore = 1;
  cursoreOld = 1;
  cursoreOld1 = 1;

  // get the number of voices in this menu
  options = getOptions();
}

byte Stato::getLanguage() {
  return salva.getLanguage();
}
byte Stato::getEepromWrite() {
  return salva.getEepromWrite();
}

// Set the cursor to next voice
void Stato::giu() {

  //  if (com == 0) {
  cursore ++;

  // if cursor is highest than the number of voices in menu set the first voice
  if (cursore > getOptions())
    cursore = 1;
}

// Set the cursor to previous voice
void Stato::su() {

  //  if (com == 0) {
  cursore --;

  // if cursor is less than one set the last voice
  if (cursore == 0)
    cursore = getOptions();
}

// Return the code of the menu
int Stato::getStato() {
  return stato;
}

// return the position of cursor
byte Stato::getCursor() {
  return cursore;
}

// Set the code of status
void Stato::setStato(int s) {

  if (stato % 10 == 0) {
    if (stato == S1) {
      cursoreOld = cursore;
    }
    else {
      cursoreOld1 = cursore;
    }
  }

  stato = s;

  if (stato % 10 == 0) {
    if (stato == S1) {
      cursore = cursoreOld;
    }
    else {
      cursore = cursoreOld1;
    }
  }
}

// Clear the cursor value for change status
void Stato::azzCursore() {
  cursore = 1;
}

// Return the number of voices for each menu
byte Stato::getOptions() {
  switch (stato) {
    case S1:
      return 5;
    case S21:
      return 4;
    case S22:
      return 4;
    case S23:
      return 5;
    case S24:
      return 3;
    case S25:
      return LANGUAGES + 1; // LANGUAGES is set in GlobalVal.h
    case S31:
    case S32:
    case S33:
      return 3;
    default:
      return 0;
  }
}

void Stato::confirm() {
  switch (stato) {
    case S1:
      stato1();
      cursore = 1;
      break;
    case S21:
      stato2_1();
      break;
    case S22:
      stato2_2();
      break;
    case S23:
      stato2_3();
      break;
    case S24:
      stato2_4();
      break;
    case S25:
      stato2_5();
      break;
    case S4:
      stato4();
      cursore = 1;
      break;
    default:
      break;
  }
}

void Stato::stato1() {
  switch (cursore) {
    case 1:
      setStato(S21);
      break;
    case 2:
      setStato(S22);
      break;
    case 3:
      setStato(S23);
      break;
    case 4:
      setStato(S24);
      break;
    case 5:
      setStato(S25);
      break;
    default:
      setStato(S1);
      break;
  }
}

int Stato::getPrint(int i) {
  switch (stato) {
    case S1:
      return getPrintS1(i);
    case S21:
      return getPrintS21(i);
    case S22:
      return getPrintS22(i);
    case S23:
      return getPrintS23(i);
    case S24:
      return getPrintS24(i);
    case S25:
      return getPrintS25(i);
    case S4:
      return getPrintS4(i);
    default:
      return getPrintS1(i);
  }
}

String Stato::getString(int i) {

  return String(i);
}

String Stato::getString(float i) {

  i = 1.1;

  return String(i);
}

// menu foto per minuto
int Stato::getPrintS21(int i) {
  switch (cursore) {
    case 1:
    case 2:
    case 3:
    case 4:
      switch (i) {
        case 1:
          return 11; // foto per min
        case 2:
          return 21; // Foto massime
        case 3:
          return 22; // avvio
        case 4:
          return 23; // indietro
        default:
          return 0;
      }
    default:
      return 0;
  }
}

// menu foto ogni
int Stato::getPrintS22(int i) {
  switch (cursore) {
    case 1:
    case 2:
    case 3:
    case 4:
      switch (i) {
        case 1:
          return 12; // Foto ogni
        case 2:
          return 21; // foto masime
        case 3:
          return 22; // Avvio
        case 4:
          return 23; // Indietro
        default:
          return 0;
      }
    default:
      return 0;
  }
}

// menu foto evento
int Stato::getPrintS23(int i) {
  switch (cursore) {
    case 1:
    case 2:
    case 3:
    case 4:
      switch (i) {
        case 1:
          return 24; // Durata evento
        case 2:
          return 25; // Durata video
        case 3:
          return 26; // Fotogrammi
        case 4:
          return 22; // Avvio
        default:
          return 0;
      }
    case 5:
      switch (i) {
        case 1:
          return 23; // indietro
        default:
          return 0;
      }
    default:
      return 0;
  }
}

// menu impostazioni
int Stato::getPrintS24(int i) {
  switch (cursore) {
    case 1:
    case 2:
    case 3:
      switch (i) {
        case 1:
          return 27; // durata AF
        case 2:
          return 28; // Durata scatto
        case 3:
          return 23; // Indietro
        default:
          return 0;
      }
    default:
      return 0;
  }
}

// menu lingua
int Stato::getPrintS25(int i) {
  switch (cursore) {
    case 1:
    case 2:
    case 3:
      switch (i) {
        case 1:
          return 251; // Italiano
        case 2:
          return 252; // Inglese
        case 3:
          return 23; // Indietro
        default:
          return 0;
      }
    default:
      return 0;
  }
}

// finale
int Stato::getPrintS4(int i) {
  switch (i){
    case 2:
      return 4;
    default:
      return 0;
  }
}

int Stato::getPrintS1(int i) {
  switch (cursore) {
    case 1:
    case 2:
    case 3:
    case 4:
      switch (i) {
        case 1:
          return 11;
        case 2:
          return 12;
        case 3:
          return 13;
        case 4:
          return 14;
        default:
          return 0;
      }
    case 5:
      switch (i) {
        case 1:
          return 15;
        default:
          return 0;
      }
    default:
      return 0;
  }
}

void Stato::stato2_1() {
  switch (cursore) {
    case 1:
      setStato(S211);
      break;
    case 2:
      setStato(S212);
      break;
    case 3:
      startPPM();
      break;
    case 4:
      setStato(S1);
      break;
    default:
      setStato(S1);
      break;
  }
}


void Stato::stato2_2() {
  switch (cursore) {
    case 1:
      setStato(S221);
      break;
    case 2:
      setStato(S222);
      break;
    case 3:
      startPEM();
      break;
    case 4:
      setStato(S1);
      break;
    default:
      setStato(S1);
      break;
  }
}
void Stato::stato2_3() {
  switch (cursore) {
    case 1:
      setStato(S231);
      break;
    case 2:
      setStato(S232);
      break;
    case 3:
      setStato(S233);
      break;
    case 4:
      startVideo();
      break;
    case 5:
      setStato(S1);
      break;
    default:
      setStato(S1);
      break;
  }
}
void Stato::stato2_4() {
  switch (cursore) {
    case 1:
      setStato(S241);
      break;
    case 2:
      setStato(S242);
      break;
    case 3:
      setStato(S1);
      break;
    default:
      setStato(S1);
      break;
  }
}
// menu lingue
void Stato::stato2_5() {
  switch (cursore) {
    case 1:
      //setStato(S1);
      break;
    case 2:
      //setStato(S1);
      break;
    case 3:
      setStato(S1);
      break;
    default:
      setStato(S1);
      break;
  }
}
void Stato::stato3() {
}

void Stato::stato4() {
  setStato(S1);
}

// return if the value of voice is int or float or no values
float Stato::getValue(int i) {

  if (cursore > 4)
    return 999;

  switch (stato) {
    case S21:
      return getValueS21(i);
    case S22:
      return getValueS22(i);
    case S23:
      return getValueS23(i);
    case S24:
      return getValueS24(i);
    default:
      return 999;
  }
}

float Stato::getValueS21(int i) {
  switch (i) {
    case 1:
      return salva.getPMin();
    case 2:
      return salva.getPMax1();
    default:
      return 999;
  }
}

float Stato::getValueS22(int i) {
  switch (i) {
    case 1:
      return salva.getPEvery();     // NON RITORNA IL VALORE CORRETTO
    case 2:
      return salva.getPMax2();
    default:
      return 999;
  }
}

float Stato::getValueS23(int i) {
  switch (i) {
    case 1:
      return salva.getRealTime();
    case 2:
      return salva.getVideoTime();
    case 3:
      return salva.getFrames();
    default:
      return 999;
  }
}

float Stato::getValueS24(int i) {
  switch (i) {
    case 1:
      return salva.getAFTime();
    case 2:
      return salva.getShoottime();
    default:
      return 999;
  }
}

float Stato::getStartVal() {
  switch (getStato()) {
    case S211:
      return getValueS21(1);
    case S212:
      return getValueS21(2);
  }
}

float Stato::valSu(float f) {
  switch (getStato()) {
    case S211:          // foto per minuto
    case S241:          // Durata AF
    case S242:          // Durata Scatto
      return f + 0.1;
    case S212:          // foto massime 1
    case S222:          // foto massime 2
      return f + 10.0;
    case S221:          // Foto al minuto
    case S232:          // Durata video
    case S233:          // Fotogrammi
      return f + 1.0;
    case S231:          // Durata evento
      return f + 5.0;
    default:
      return f + 1.0;
  }
}

float Stato::valGiu(float f) {
  switch (getStato()) {
    case S211:          // foto per minuto
    case S241:          // Durata AF
    case S242:          // Durata Scatto
      return f - 0.1;
    case S212:          // foto massime 1
    case S222:          // foto massime 2
      return f - 10.0;
    case S221:          // Foto al minuto
    case S232:          // Durata video
    case S233:          // Fotogrammi
      return f - 1.0;
    case S231:          // Durata evento
      return f - 5.0;
    default:
      return f - 1.0;
  }
}

int Stato::getPos() {
  switch (getStato()) {
    case S211:          // foto per minuto
    case S221:          // Foto al minuto
    case S231:          // Durata evento
      return 0;
    case S212:          // foto massime 1
    case S222:          // foto massime 2
    case S232:          // Durata video
    case S242:          // Durata Scatto
      return 1;
    case S233:          // Fotogrammi
      return 2;
    default:
      return 0;
  }
}

void Stato::salvaVal(float f) {
  switch (getStato()) {
    case S211:
      return salva.setPMin(f);
    case S212:
      return salva.setPMax1(int(f));
    case S221:
      return salva.setPEvery(int(f));
    case S222:
      return salva.setPMax2(int(f));
    case S231:
      return salva.setRealTime(int(f));
    case S232:
      return salva.setVideoTime(int(f));
    case S233:
      return salva.setFrames(byte(f));
    case S241:
      return salva.setAFTime(f);
    case S242:
      return salva.setShoottime(f);
    default:
      return 0;
  }
}

boolean Stato::isStart() {
  switch (stato) {
    case S31:
    case S32:
    case S33:
    //case S4:
      return 1;
    default:
      return 0;
  }
}

boolean Stato::isMenu() {
  switch (stato) {
    case S1:
    case S21:
    case S22:
    case S23:
    case S24:
    case S25:
    case S4:
      return 1;
    default:
      return 0;
  }
}

// stato di modifica valore
boolean Stato::isChange() {
  switch (stato) {
    case S211:
    case S212:
    case S221:
    case S222:
    case S231:
    case S232:
    case S233:
    case S241:
    case S242:
      return 1;
    default:
      return 0;
  }
}

void Stato::startPPM() { // foto al minuto
  setStato(S31);
  start = millis();   // Time di quando iniziato
  last = start;
  delta = int (60000 / salva.getPMin()); // moltiplico un minuto per il valore di foto al minuto
  count = 0;   // Quante foto sono state fatte
  finish = salva.getPMax1();  // quante foto da fare per terminare
}

void Stato::startPEM() {   // foto ogni x minuti
  setStato(S32);
  start = millis();   // Time di quando iniziato
  last = start;
  delta = salva.getPEvery() * 60000; // moltiplico un minuto per il numero di minuti ogni quanto fare la foto
  count = 0;   // Quante foto sono state fatte
  finish = salva.getPMax2();  // quante foto da fare per terminare
}

void Stato::startVideo() { // foto per video
  setStato(S33);
  start = millis();   // Time di quando iniziato
  last = start;
  finish = int (salva.getVideoTime() * salva.getFrames());
  delta = int (salva.getRealTime() * 60000 / finish);
  count = 0;   // Quante foto sono state fatte
}

int Stato::shooting() {
  if (millis() > (last + delta) and count < finish) {
    last = millis();
    count ++;
    if (count >= finish){
      setStato(S4);
      return 2;
    }
    return 1;
  }
  return 0;
}

void Stato::scattato() {
  scatta = 0;
}

boolean Stato::getScattato() {
  return scatta;
}

int Stato::getStatoName() {
  switch (stato) {
    case S31:
      return 11;
    case S32:
      return 12;
    case S33:
      return 13;
    default:
      return 11;
  }
}

unsigned long Stato::timing() {
  return millis() - start;
}

void Stato::reset() {
  setStato(S1);
  cursore = 1;
  cursoreOld = 1;
  cursoreOld1 = 1;
}

unsigned int Stato::getCount() {
  return count;
}

int Stato::getFTime() {
  return int (salva.getAFTime() * 1000);
}

int Stato::getShoottime() {
  return int (salva.getShoottime() * 1000);
}

