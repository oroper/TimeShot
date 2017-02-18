/*
   This class manage the information about encoder module

*/

#include "Encoder.h"

Encoder::Encoder()
{
  DT = LOW;  // Value of DT on encoder
  CL = LOW;  // Value of CLOCK on encoder

  DTO = LOW; // Old value of DT
  CLO = LOW; // Old value of CL

}

// This function is called from Interrupt service routing
void Encoder::encoderCh() {
  // Read the value of DT
  DT = digitalRead(PinDT); //PIND & 0B00000100;
  // Read the value of CL
  CL = digitalRead(PinCL); //PIND & 0B00001000;

  // verify the status of Encoder to decide if rotation is on right or left
  if ( ((DTO == 1 && CLO == 1) && DT == 1 && CL == 0) || ((DTO == 0 && CLO == 0) && DT == 0 && CL == 1) ) {
    giu = HIGH; // Rotation on right
    //Serial.println(n);
  }
  else if ( ((DTO == 1 && CLO == 1) && DT == 0 && CL == 1) || ((DTO == 0 && CLO == 0) && DT == 1 && CL == 0) ) {
    su = HIGH;  // Rotation on left
    //Serial.println(n);
  }

  /*
    Serial.print("DT ");
    Serial.println(DT);
    Serial.print("CL ");
    Serial.println(CL);
    Serial.println("-----------");
  */

  //Update the Old value of DT and CL
  DTO = DT; // aggiorno i valori passati
  CLO = CL; // aggiorno i valori passati

  delay(50);
}

byte Encoder::getGiu() {
  return giu;
}

byte Encoder::getSu() {
  return su;
}

// Clear the information of rotation
void Encoder::azzera() {
  giu = LOW;
  su = LOW;
  delay(15);
}

// Return True if the button is pressed
byte Encoder::pressed() {
  return !digitalRead(PinSW);
}


