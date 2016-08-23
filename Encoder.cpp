#include "Encoder.h"

Encoder::Encoder()
{
  DT = LOW;  // valore assunto da DT
  CL = LOW;  // valore assunto da CLOCK

  DTO = LOW;  // valore precedente di DT
  CLO = LOW; // vaalore precedente di CLOCK

}

void Encoder::encoderCh(){
  DT = digitalRead(PinDT); //PIND & 0B00000100;
  CL = digitalRead(PinCL); //PIND & 0B00001000;


  if ( ((DTO == 1 && CLO == 1) && DT == 1 && CL == 0) || ((DTO == 0 && CLO == 0) && DT == 0 && CL == 1) ){
    giu = HIGH;
    //Serial.println(n);
  }
  else if ( ((DTO == 1 && CLO == 1) && DT == 0 && CL == 1) || ((DTO == 0 && CLO == 0) && DT == 1 && CL == 0) ){
    su = HIGH;
    //Serial.println(n);
  }

  /*
   Serial.print("DT ");
   Serial.println(DT);
   Serial.print("CL ");
   Serial.println(CL);
   Serial.println("-----------");
   */

  DTO = DT; // aggiorno i valori passati
  CLO = CL; // aggiorno i valori passati

  delay(50);
}

byte Encoder::getGiu(){
  return giu;
}

byte Encoder::getSu(){
  return su;
}

void Encoder::azzera(){
  giu = LOW;
  su = LOW; 
}

byte Encoder::pressed(){
  return !digitalRead(PinSW);
}

