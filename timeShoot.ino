#include "Monitor.h"
#include "Encoder.h"
#include "Stato.h"
#include "Salva.h"

#include <LiquidCrystal.h>

Monitor monitor;
Stato stato;
Encoder encoder;
Salva salva;


void setup() {

  pinMode(PinCL, INPUT);
  digitalWrite(PinCL, HIGH);

  pinMode(PinDT, INPUT);
  digitalWrite(PinDT, HIGH);

  pinMode(PinSW, INPUT);


  attachInterrupt(0, isr, CHANGE); // imposto interrupt con isr (interrupt service routine)
  attachInterrupt(1, isr, CHANGE); // imposto interrupt con isr (interrupt service routine) 

Serial.begin(9600);

  //monitor.aggiorna(stato);
  monitor.setLanguage(salva.getLanguage());
  
  delay(1000);
  
  monitor.aggiorna(stato);

}

void loop() {
  
  if (encoder.getGiu() == HIGH){
    stato.giu();
    encoder.azzera();

    monitor.aggiorna(stato);
  }

  else if (encoder.getSu() == HIGH){
    stato.su();
    encoder.azzera();

    monitor.aggiorna(stato);
  }
  
  else if (encoder.pressed()){
    
    stato.confirm();
 
    monitor.aggiorna(stato);
    
  }

}

void isr(){
  encoder.encoderCh();
}




