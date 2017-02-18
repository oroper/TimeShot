#ifndef Languages_h
#define Languages_h

#include "Arduino.h"
#include "GlobalVal.h"

class Languages {

  public:
    Languages();

    void setLanguage(int);
    int getLanguage();
    String getString(int);


  private:
    int language;

};

#endif
