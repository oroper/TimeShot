#ifndef Monitor_h
#define Monitor_h

#include "Arduino.h"
#include <LiquidCrystal.h>
#include "Stato.h"
#include "Boot.h"
#include "Languages.h"

class Monitor {

  LiquidCrystal lcd;
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
  byte language;

};

#endif



