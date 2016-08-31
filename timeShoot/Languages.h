#ifndef Languages_h
#define Languages_h

#include "Arduino.h"
#include "GlobalVal.h"

class Languages {

public:
  Languages();
  
  void setLanguage(byte);
  String getString(String);
  

private:
  byte language;

};

#endif
