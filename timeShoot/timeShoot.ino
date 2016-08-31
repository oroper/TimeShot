/*
   TimeShoot
   Version 1.0

   This program is to do a module to do picture temporizzed with a reflex camera.

*/

#include "Monitor.h"
#include "Encoder.h"
#include "Stato.h"

Monitor monitor;  // object that rappresents the LCD
Stato stato;      // object that rappresents the status of system
Encoder encoder;  // object that rappresents the comenad of encoder
//Salva salva;      // object that rappresents the eeprom information storage

void setup() {

  // set Pin that corrispons to the rotation to right of the encoder
  pinMode(PinCL, INPUT);
  digitalWrite(PinCL, HIGH);

  // set Pin that corrispons to the rotation to left of the encoder
  pinMode(PinDT, INPUT);
  digitalWrite(PinDT, HIGH);

  // set Pin that corrispons to the pression of button of encoder
  pinMode(PinSW, INPUT);

  // set the Interrupt Service Routin for the rotation of encoder
  attachInterrupt(0, isr, CHANGE);
  attachInterrupt(1, isr, CHANGE);

  // Keep information about language from eeprom
  monitor.setLanguage(stato.getLanguage());

  // Wait to see the starting screen
  delay(1000);

  monitor.stampa(stato.getEepromWrite());

  //delay(2000);

  // Print start menu
  monitor.aggiorna(stato);

}

void loop() {

  // Verify if encoder was rotated
  if (encoder.getGiu() == HIGH) {
    // put the cursor to next voice
    stato.giu();
    // Cler the information about Encoder rotation
    encoder.azzera();
    // Update the screen view
    monitor.aggiorna(stato);
  }

  else if (encoder.getSu() == HIGH) {
    // put the cursor to previous voice
    stato.su();
    // Cler the information about Encoder rotation
    encoder.azzera();
    // Update the screen view
    monitor.aggiorna(stato);
  }

  // verify if the button is pressed
  else if (encoder.pressed()) {
    // Call the function to execute the pression
    stato.confirm();
    // Update the screen view
    monitor.aggiorna(stato);
    // time needed to not have double click
    delay (500);
  }
}

// Interrupt service routing
void isr() {
  // call tha function in encoder object
  encoder.encoderCh();
}




