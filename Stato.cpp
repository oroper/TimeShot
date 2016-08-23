#include "Stato.h"

// stato 1: menu principale - 5 opzioni
// stato 2_1: menu foto al minuto - 4 opzioni
// stato 2_2: menu foto ogni n minuti - 4 opzioni
// stato 2_3: menu foto per video - 5 opzioni
// stato 2_4: menu impostazioni - 3 opzioni
// stato 2_5: menu lingua - lingua opzioni + 1
// stato 3: schermata running - 3 opzioni

Stato::Stato(){

  stato = S1;

  cursore = 1;

  options = getOptions();
}

void Stato::giu(){
  cursore ++;

  if (cursore > getOptions())
    cursore = 1;
}

void Stato::su(){
  cursore --;

  if (cursore == 0)
    cursore = getOptions();
}

byte Stato::getStato(){
  return stato;
}

byte Stato::getCursor(){
  return cursore;
}


void Stato::setStato(int s){
  stato = s;
}

void Stato::azzCursore(){
  cursore = 1;
}

byte Stato::getOptions(){
  switch (stato){
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
    return LANGUAGES + 1;
  case S3:
    return 3;
  }
}

void Stato::confirm(){
  switch (stato){
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

void Stato::stato1(){
  switch (cursore){
  case 1:
    setStato(S21);
    azzCursore();
    break;
  case 2:
    setStato(S22);
    azzCursore();
    break;
  case 3:
    setStato(S23);
    azzCursore();
    break;
  case 4:
    setStato(S24);
    azzCursore();
    break;
  case 5:
    setStato(S25);
    azzCursore();
    break;
  default:
    setStato(S1);
    azzCursore();
    break;
  }
}

String Stato::getPrint(int i){
  switch (stato){
  case S1:
    return getPrintS1(i);
  case S21:
    return getPrintS21(i);
  }
}

String Stato::getPrintS21(int i){
  switch (cursore){
  case 1:
  case 2:
    switch (i){
    case 1:
      return "1_1"; // primo come titolo
    case 2:
      return "2_M";
    }
  case 3:
  case 4:
    switch (i){
    case 1:
      return "2_A";
    case 2:
      return "2_I";
    }
  }
}

String Stato::getPrintS1(int i){
  switch (cursore){
  case 1:
  case 2:
    switch (i){
    case 1:
      return "1_1";
    case 2:
      return "1_2";
    }
  case 3:
  case 4:
    switch (i){
    case 1:
      return "1_3";
    case 2:
      return "1_4";
    }
  case 5:
  case 6:
    switch (i){
    case 1:
      return "1_5";
    case 2:
      return "empty";
    }
  }
}

void Stato::stato2_1(){
    switch (cursore){
  case 1:
    //setStato(S21);
    azzCursore();
    break;
  case 2:
    //setStato(S22);
    azzCursore();
    break;
  case 3:
    //setStato(S23);
    azzCursore();
    break;
  case 4:
    setStato(S1);
    azzCursore();
    break;
  default:
    setStato(S1);
    azzCursore();
    break;
  }
}
void Stato::stato2_2(){
}
void Stato::stato2_3(){
}
void Stato::stato2_4(){
}
void Stato::stato2_5(){
}
void Stato::stato3(){
}














