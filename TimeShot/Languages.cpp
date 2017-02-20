/*
   This calss contains all the string of program in the differents languages.

   NOTE: Mettere un defalut nelle stringhe di ritorno
*/

#include "Languages.h"

Languages::Languages() {

}

// set the language
void Languages::setLanguage(int l) {
  language = 1;
}

// get the language
int Languages::getLanguage() {
  language;
}

String Languages::getString(int s) {
  if (s == 11) {
    //    if (getLanguage() == 1)
    return "Foto per min";
    //    if (language == 2)
    //      return "Picture in min";
  }

  else if (s == 12) {
    //    if (language == 1)
    return "Foto ogni";
    //    if (language == 2)
    //      return "Picture each";
  }

  else if (s == 13) {
    //    if (language == 1)
    return "Foto video";
    //    if (language == 2)
    //      return "Picture video";
  }

  else if (s == 14) {
    //    if (language == 1)
    return "Impostazioni";
    //    if (language == 2)
    //      return "Setttings";
  }

  else if (s == 15) {
    //    if (language == 1)
    return "Lingua";
    //    if (language == 2)
    //      return "Languages";
  }

  else if (s == 21) {
    //if (language == 1)
    return "Foto massime";
    // if (language == 2)
    //  return "Max picture";
  }

  else if (s == 22) {
    //  if (language == 1)
    return "Avvio";
    //  if (language == 2)
    //    return "Start";
  }

  else if (s == 23) {
    //  if (language == 1)
    return "Indietro";
    //  if (language == 2)
    //  return "Back";
  }

  else if (s == 24) {
    //    if (language == 1)
    return "Durata evento";
    //    if (language == 2)
    //     return "Event duration";
  }

  else if (s == 25) {
    //    if (language == 1)
    return "Durata video";
    //    if (language == 2)
    //      return "Video duration";
  }

  else if (s == 26) {
    //    if (language == 1)
    return "Fotogrammi";
    //    if (language == 2)
    //      return "Frames";
  }

  else if (s == 27) {
    //    if (language == 1)
    return "Durata AF";
    //    if (language == 2)
    //      return "AF time";
  }

  else if (s == 28) {
    //    if (language == 1)
    return "Durata scatto";
    //    if (language == 2)
    //      return "Shoot time";
  }

  else if (s == 251) {
    //    if (language == 1)
    return "Italiano";
    //    if (language == 2)
    //      return "Italian";
  }

  else if (s == 252) {
    //    if (language == 1)
    return "Inglese";
    //    if (language == 2)
    //      return "English";
  }

  else if (s == 211) {
    //    if (language == 1)
    return "foto";
    //    if (language == 2)
    //      return "pictures";
  }

  else if (s == 212) {
    //    if (language == 1)
    return "min";
    //    if (language == 2)
    //      return "min";
  }

  else if (s == 213) {
    //    if (language == 1)
    return "sec";
    //    if (language == 2)
    //      return "sec";
  }

  else if (s == 214) {
    //    if (language == 1)
    return "f/min";
    //    if (language == 2)
    //      return "p/min";
  }

  else if (s == 31) {
    //    if (language == 1)
    return "Tempo";
    //    if (language == 2)
    //      return "Time";
  }

  else if (s == 32) {
    //    if (language == 1)
    return "Scatti";
    //    if (language == 2)
    //      return "Shots";
  }

  else if (s == 33) {
    //    if (language == 1)
    return "Stop";
    //    if (language == 2)
    //      return "Stop";
  }
  else if (s == 34) {
    //    if (language == 1)
    return "Scatti";
    //    if (language == 2)
    //      return "Scatti";
  }
  else if (s == 35) {
    //    if (language == 1)
    return "Tempo";
    //    if (language == 2)
    //      return "Timing";
  }

  else if (s == 0) {
    return "";
  }
}


