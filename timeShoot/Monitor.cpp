/*
   This clas manage the printing to the LCD
*/

#include "Monitor.h"

// inizializing the LCD
Monitor::Monitor() :
  lcd(8, 9, 4, 5, 6, 7) {

  lcd.begin(16, row); // will be a (20,4) I2C LCD

  // Generation of arrow character
  lcd.createChar(5, arrow);

  // call the function to print the starting screen
  boot();

}

// Print the passed String
void Monitor::stampa(String s) {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s);
}

// print the status of passed stato object
void Monitor::stampa(Stato s) {

  lcd.setCursor(0, 1);
  lcd.print(byte(s.getStato()));
}

// Print the int value passed
void Monitor::stampa(int i) {

  lcd.setCursor(1, 1);
  lcd.print(i);

}

// Update the screen view
void Monitor::aggiorna(Stato s) {

  lcd.clear();

  // Set cursor rispect the row of the LCD
  lcd.setCursor(0, (s.getCursor() % row) - 1 ); // get the cursor position, keep the module and reduce 1, I obtain the row position in the LCD
  lcd.write(byte(5));

  // Print the string of current position
  printStato(s);


}

// This function Print on LCD the menu field in the correct positions
void Monitor::printStato(Stato s) {
  static int i;

  // for each row of LCD print the correct voices of menu
  for (i = 0; i < row; i++) {
    lcd.setCursor(1, i);
    // obtain the reference coede of voice from S, send the code to Language to keep the string in the setted language
    lcd.print(languages.getString(s.getPrint(i + 1)));

    lcd.setCursor(col - 4, i);
    lcd.print(s.getValue(i + 1));
  }
}

// set the language
void Monitor::setLanguage(byte l) {

  languages.setLanguage(l);
}

// print hte starting screen
void Monitor::boot() {

  static int x;

  lcd.setCursor(3, 0);

  lcd.print("Timeshoot");

  // create the different needed characters
  lcd.createChar(0, v);
  lcd.createChar(1, ee);
  lcd.createChar(2, r);
  lcd.createChar(3, u);
  lcd.createChar(4, z);

  lcd.setCursor(5, 1);

  for (x = 0; x < 5; x++) {
    lcd.write(byte(x));
  }

}




