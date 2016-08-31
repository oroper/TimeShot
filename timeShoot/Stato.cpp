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

// inizialize the object
Stato::Stato() {

  // Start from first menu
  stato = S1;

  // cursor on first voice
  cursore = 1;

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

  if (com == 0) {
    cursore ++;

    // if cursor is highest than the number of voices in menu set the first voice
    if (cursore > getOptions())
      cursore = 1;
  }

  else {
    comNext();
  }
}

// Set the cursor to previous voice
void Stato::su() {

  if (com == 0) {
    cursore --;

    // if cursor is less than one set the last voice
    if (cursore == 0)
      cursore = getOptions();
  }
  else {
    comPrev();
  }
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

  stato = s;

  azzCursore();
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
    case S3:
      return 3;
  }
}

void Stato::confirm() {
  switch (stato) {
    case S1:
      stato1();
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
    case S3:
      stato3();
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

String Stato::getPrint(int i) {
  switch (stato) {
    case S1:
      return getPrintS1(i);
    case S21:
      return getPrintS21(i);
    case S22:
      return getPrintS22(i);
  }
}

// return if the value of voice is int or float or no values
String Stato::getValue(int i) {
  switch (stato) {
    case S1:
      return "";
    case S21:
      return getValueS21(i);
    case S22:
      return getValueS22(i);
  }

}



String Stato::getString(int i) {

  return String(i);
}

String Stato::getString(float i) {

  i = 1.1;

  return String(i);
}

String Stato::getPrintS21(int i) {
  switch (cursore) {
    case 1:
    case 2:
      switch (i) {
        case 1:
          return "1_1"; // primo come titolo
        case 2:
          return "2_M";
      }
    case 3:
    case 4:
      switch (i) {
        case 1:
          return "2_A";
        case 2:
          return "2_I";
      }
  }
}

String Stato::getPrintS22(int i) {
  switch (cursore) {
    case 1:
    case 2:
      switch (i) {
        case 1:
          return "1_2"; // primo come titolo
        case 2:
          return "2_M";
      }
    case 3:
    case 4:
      switch (i) {
        case 1:
          return "2_A";
        case 2:
          return "2_I";
      }
  }
}

String Stato::getValueS21(int i) {
  switch (cursore) {
    case 1:
    case 2:
      switch (i) {
        case 1:
          if (com != 0 && cursore == 1)
            return String(getCommand());
          else
            return String(salva.getPMin());
        case 2:
          if (com != 0 && cursore == 2)
            return String(getCommand());
          else
            return String(salva.getPMax1());
      }
    default :
      return "";
  }
}

String Stato::getCommand() {
  if (com == 1)
    return String (comInt);
  else if (com == 2)
    return String (comFloat);

}

String Stato::getValueS22(int i) {
  switch (cursore) {
    case 1:
    case 2:
      switch (i) {
        case 1:
          if (com == 0)
            return String(salva.getPEvery());
          else
            return String(getCommand());
        case 2:
          if (com == 0)
            return String(salva.getPMax2());
          else
            return String(getCommand());
      }
    default :
      return "";
  }
}

String Stato::getPrintS1(int i) {
  switch (cursore) {
    case 1:
    case 2:
      switch (i) {
        case 1:
          return "1_1";
        case 2:
          return "1_2";
      }
    case 3:
    case 4:
      switch (i) {
        case 1:
          return "1_3";
        case 2:
          return "1_4";
      }
    case 5:
    case 6:
      switch (i) {
        case 1:
          return "1_5";
        case 2:
          return "empty";
      }
  }
}

void Stato::stato2_1() {
  switch (cursore) {
    case 1:
      command21_1();
      break;
    case 2:
      //setStato(S1);
      break;
    case 3:
      //setStato(S1);
      break;
    case 4:
      setStato(S1);
      break;
    default:
      setStato(S1);
      break;
  }
}

void Stato::command21_1() {
  if (com == 0) {
    com = 2;
    comFloat = salva.getPMin();
  }
  else {
    salva.setPMin(comFloat);
    comFloat = 0.0;
    com = 0;
  }
}

void Stato::comPrev() {
  if (com == 1)
    comInt --;
  else if (com == 2)
    comFloat = comFloat - 0.1;
}

void Stato::comNext() {
  if (com == 1)
    comInt ++;
  else if (com == 2)
    comFloat = comFloat + 0.1;
}

void Stato::stato2_2() {
  switch (cursore) {
    case 1:
      //setStato(S1);
      break;
    case 2:
      //setStato(S1);
      break;
    case 3:
      //setStato(S1);
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
}
void Stato::stato2_4() {
}
void Stato::stato2_5() {
}
void Stato::stato3() {
}














