#include "Languages.h"


Languages::Languages(){ 

}

void Languages::setLanguage(byte l){
  language = l;
}

String Languages::getString(String s){
  if (s == "1_1"){
    if(language == 1)
      return "Foto per min";
    if(language == 2)
      return "Picture in min";
  }

  else if (s == "1_2"){
    if(language == 1)
      return "Foto ogn";
    if(language == 2)
      return "Picture each";
  }

  else if (s == "1_3"){
    if(language == 1)
      return "Foto video";
    if(language == 2)
      return "Picture video";
  }

  else if (s == "1_4"){
    if(language == 1)
      return "Imp";
    if(language == 2)
      return "Setttings";
  }

  else if (s == "1_5"){
    if(language == 1)
      return "Lingua";
    if(language == 2)
      return "Languages";
  }
  
    else if (s == "2_M"){
    if(language == 1)
      return "Foto massime";
    if(language == 2)
      return "Max picture";
  }
  
      else if (s == "2_A"){
    if(language == 1)
      return "Avvio";
    if(language == 2)
      return "Start";
  }
  
        else if (s == "2_I"){
    if(language == 1)
      return "Indietro";
    if(language == 2)
      return "Back";
  }

  else if (s == "empty"){
    return "******";
  }
}


