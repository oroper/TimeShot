#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

#define PinCL 2   // Pin of right encoder rotation (interrupt 0)
#define PinDT 3   // Pin of left encoder rotation (interrupt 1)
#define PinSW 4  // Button pin

class Encoder
{
  public:
    Encoder();
    void encoderCh();   // This function is called from Interrupt service routing
    byte getGiu();
    byte getSu();
    void azzera();      // Clear the information of rotation
    byte pressed();     // Return True if the button is pressed

  private:

    byte giu;   // If the encoder was rotated to right this variable is set to True
    byte su;    // If the encoder was rotated to left this variable is set to True

    byte DT;    // valore assunto da DT
    byte CL;    // valore assunto da CLOCK

    byte DTO;   // valore precedente di DT
    byte CLO;   // vaalore precedente di CLOCK
};

#endif


