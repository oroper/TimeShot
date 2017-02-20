#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Boot.h"
#include "GlobalVal.h"
#include "Languages.h"
#include "Salva.h"
#include "Stato.h"
#include "Encoder.h"

const byte row = 4;//2;       // contain the number of row of LCD
const byte col = 20;

Salva salva;
Languages languages;
Stato stato;
Encoder encoder;

LiquidCrystal_I2C lcd(0x3F, col, row);

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

  lcd.init();
  lcd.backlight();

  lcd.clear();

  boot();
  delay(500);
  aggiorna();

  delay(2000);

}

void loop() {

  if (stato.getStato() == 300) {
    if (stato.getScattato())
      scatta();
    else if (encoder.getSu()) {
      encoder.azzera();
    }
    else if (encoder.getGiu()) {
      encoder.azzera();
    }
    else if (encoder.pressed()) {
      stato.setStato(100);
      encoder.azzera();
      delay(1000);
    }
    esecuzione();
  }
  else if (stato.getStato() % 10 == 0) {
    if (encoder.getSu()) {
      stato.su();
      aggiorna();
    }
    else if (encoder.getGiu()) {
      stato.giu();
      aggiorna();
    }
    else if (encoder.pressed()) {
      stato.confirm();
      if (stato.getStato() % 10 == 0) {
        aggiorna();
      }
      delay(1000);
    }
  }
  // modifica di un valore
  else {
    float f = stato.getStartVal();
    while (!encoder.pressed()) {
      if (encoder.getSu()) {
        encoder.azzera();
        printVal(stato.getPos(), stato.valSu(f));
        f = stato.valSu(f);
      }
      else if (encoder.getGiu()) {
        encoder.azzera();
        printVal(stato.getPos(), stato.valGiu(f));
        f = stato.valGiu(f);
      }
    }
    stato.salvaVal(f);
    stato.setStato(stato.getStato() / 10 * 10);
    aggiorna();
    delay(1000);
  }
}

void aggiorna() {
  lcd.clear();

  // Set cursor rispect the row of the LCD
  lcd.setCursor(0, (stato.getCursor() % row) - 1 ); // get the cursor position, keep the module and reduce 1, I obtain the row position in the LCD
  lcd.write(byte(5));

  // Print the string of current position
  printStato();

  encoder.azzera();
}

// This function Print on LCD the menu field in the correct positions
void printStato() {
  static int i;
  /*
    lcd.setCursor(1, 0);
    lcd.print(languages.getString(stato.getPrint(1)));
    lcd.setCursor(1, 1);
    lcd.print(languages.getString(stato.getPrint(2)));
  */
  // for each row of LCD print the correct voices of menu
  for (i = 0; i < row; i++) {
    lcd.setCursor(1, i);
    // obtain the reference coede of voice from S, send the code to Language to keep the string in the setted language
    lcd.print(languages.getString(stato.getPrint(i + 1)));

    float v = stato.getValue(i + 1);

    if ( v != 999.0) {
      printVal(i, v);
    }
  }

}

void printVal(int i, float v) {
  lcd.setCursor(16, i);
  lcd.print("    ");
  lcd.setCursor(16, i);
  //int p = int(v * 10) % 10;
  if (int (v * 10) % 10 == 0)
    lcd.print(int (v));
  else
    lcd.print(v);
}

void boot() {
  static int x;

  lcd.setCursor(4, 1);

  lcd.print("Timeshoot");

  // create the different needed characters
  lcd.createChar(0, v);
  lcd.createChar(1, ee);
  lcd.createChar(2, r);
  lcd.createChar(3, u);
  lcd.createChar(4, z);
  lcd.createChar(5, arrow);

  lcd.setCursor(6, 2);

  for (x = 0; x < 5; x++) {
    lcd.write(byte(x));
  }
}

void isr() {
  // call tha function in encoder object
  encoder.encoderCh();
}

void esecuzione() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(languages.getString(stato.getStatoName()));
  lcd.setCursor(0, 1);
  lcd.print(languages.getString(34)); // scatti
  lcd.setCursor(10, 1);
  lcd.print(stato.getCount()); // scatti
  lcd.setCursor(0, 2);
  lcd.print(languages.getString(35)); // tempo
  lcd.setCursor(10, 2);
  lcd.print(stato.timing() / 1000 / 60);
  lcd.print(":");
  lcd.print((stato.timing() / 1000) % 60);
}

void scatta(){
  
}

