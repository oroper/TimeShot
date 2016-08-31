#ifndef Monitor_h
#define Monitor_h

#include "Arduino.h"
#include <LiquidCrystal.h>
#include "Stato.h"
#include "Boot.h"
#include "Languages.h"
#include "GlobalVal.h"

class Monitor {

  // Inizialize the LCD
  LiquidCrystal lcd;
  // Create a object Language
  Languages languages;

public:
  Monitor();
  void stampa(String);
  void stampa(Stato);
  void stampa(int);
  void aggiorna(Stato);
  void setLanguage(byte);

private:
  void boot();
  void printStato(Stato);
  const byte row = 2;       // contain the number of row of LCD
  const byte col = 16;      // contain the number of colomn of LCD

};

#endif



