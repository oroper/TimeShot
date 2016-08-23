#include "Monitor.h"


Monitor::Monitor() : 
lcd(8, 9, 4, 5, 6, 7) {

  lcd.begin(16,2);

  lcd.createChar(5, arrow);

  boot();

}

void Monitor::stampa(String s){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s);

}

void Monitor::stampa(Stato s){

  lcd.setCursor(0, 1);
  lcd.print(byte(s.getStato()));

}

void Monitor::stampa(int i){

  lcd.setCursor(1, 1);
  lcd.print(i);

}

void Monitor::aggiorna(Stato s){

  lcd.clear();

  if (s.getCursor()%2 == 1){
    lcd.setCursor(0, 0);
    lcd.write(byte(5));

  }
  else if (s.getCursor()%2 == 0){
    lcd.setCursor(0, 1);
    lcd.write(byte(5));
  }

  printStato(s);


}

void Monitor::printStato(Stato s){
  lcd.setCursor(1,0);
  lcd.print(languages.getString(s.getPrint(1)));
  lcd.setCursor(1,1);
  lcd.print(languages.getString(s.getPrint(2)));
}

void Monitor::setLanguage(byte l){
  
  languages.setLanguage(l);
}

void Monitor::boot(){

  static int x;

  lcd.setCursor(3, 0);

  lcd.print("Timeshoot");

  lcd.createChar(0, v);
  lcd.createChar(1, ee);
  lcd.createChar(2, r);
  lcd.createChar(3, u);
  lcd.createChar(4, z);

  lcd.setCursor(5, 1);

  for(x = 0; x < 5; x++){
    lcd.write(byte(x));
  }

}




