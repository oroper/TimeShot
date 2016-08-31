/*
   This calss contains all the string of program in the differents languages.

   NOTE: Mettere un defalut nelle stringhe di ritorno
*/

#include "Languages.h"

Languages::Languages() {

}

// set the language
void Languages::setLanguage(byte l) {
  language = l;
}

String Languages::getString(String s) {
  if (s == "1_1") {
    if (language == 1)
      return "Foto per min";
    if (language == 2)
      return "Picture in min";
  }

  else if (s == "1_2") {
    if (language == 1)
      return "Foto ogni";
    if (language == 2)
      return "Picture each";
  }

  else if (s == "1_3") {
    if (language == 1)
      return "Foto video";
    if (language == 2)
      return "Picture video";
  }

  else if (s == "1_4") {
    if (language == 1)
      return "Impostazioni";
    if (language == 2)
      return "Setttings";
  }

  else if (s == "1_5") {
    if (language == 1)
      return "Lingua";
    if (language == 2)
      return "Languages";
  }

  else if (s == "2_M") {
    if (language == 1)
      return "Foto massime";
    if (language == 2)
      return "Max picture";
  }

  else if (s == "2_A") {
    if (language == 1)
      return "Avvio";
    if (language == 2)
      return "Start";
  }

  else if (s == "2_I") {
    if (language == 1)
      return "Indietro";
    if (language == 2)
      return "Back";
  }

  else if (s == "2_3_DR") {
    if (language == 1)
      return "Durata evento";
    if (language == 2)
      return "Event duration";
  }

  else if (s == "2_3_DV") {
    if (language == 1)
      return "Durata video";
    if (language == 2)
      return "Video duration";
  }

  else if (s == "2_3_F") {
    if (language == 1)
      return "Fotogrammi";
    if (language == 2)
      return "Frames";
  }

  else if (s == "2_4_AF") {
    if (language == 1)
      return "Durata AF";
    if (language == 2)
      return "AF time";
  }

  else if (s == "2_4_DS") {
    if (language == 1)
      return "Durata scatto";
    if (language == 2)
      return "Shoot time";
  }

  else if (s == "2_5_IT") {
    if (language == 1)
      return "Italiano";
    if (language == 2)
      return "Italian";
  }

  else if (s == "2_5_EN") {
    if (language == 1)
      return "Inglese";
    if (language == 2)
      return "English";
  }

  else if (s == "2_F") {
    if (language == 1)
      return "foto";
    if (language == 2)
      return "pictures";
  }

  else if (s == "2_M") {
    if (language == 1)
      return "min";
    if (language == 2)
      return "min";
  }

  else if (s == "2_S") {
    if (language == 1)
      return "sec";
    if (language == 2)
      return "sec";
  }

  else if (s == "2_FM") {
    if (language == 1)
      return "f/min";
    if (language == 2)
      return "p/min";
  }

  else if (s == "3_T") {
    if (language == 1)
      return "Tempo";
    if (language == 2)
      return "Time";
  }

  else if (s == "3_S") {
    if (language == 1)
      return "Scatti";
    if (language == 2)
      return "Shots";
  }

  else if (s == "3_ST") {
    if (language == 1)
      return "Stop";
    if (language == 2)
      return "Stop";
  }

  else if (s == "empty") {
    return "";
  }
}


