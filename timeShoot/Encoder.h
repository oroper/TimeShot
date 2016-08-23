#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

#define PinCL 2 // pin interrupt 0
#define PinDT 3 // pin interrupt 1
#define PinSW 12 // pin del pulsante

class Encoder
{
public:
  Encoder();
  void encoderCh();
  byte getGiu();
  byte getSu();
  void azzera();
  byte pressed();

private:

  byte giu;
  byte su;

  byte DT;  // valore assunto da DT
  byte CL;  // valore assunto da CLOCK

  byte DTO;  // valore precedente di DT
  byte CLO; // vaalore precedente di CLOCK
};

#endif

