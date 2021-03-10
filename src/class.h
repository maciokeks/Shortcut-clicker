#include "pins.h"
class Button{
  public:
  int pin;
  int state;
  bool inverted;
  long starttimer;
  long stoptimer;
  long elapsedtimer;
  String key;
public:
  Button(int p, bool i,String k){
    pin = p;
    inverted = i;
    key = k;
    beginn();
  }
  void beginn(){
    pinMode(pin,INPUT_PULLUP);
  }
  int getstate(){
    switch(inverted){
      case true:
        if(digitalRead(pin)==HIGH){
            state = 0;
            return state;
        }else if(digitalRead(pin)==LOW){
            state = 1;
            return state;
        }
      break;
      case false:
        if(digitalRead(pin)==HIGH){
            state = 1;
            return state;
        }else if(digitalRead(pin)==LOW){
            state = 0;
            return state;            
        }
      break;
    }
  }
 ~Button(){}
};

class Led{
  public:
  void rgb_led(int button, int R, int G, int B){
    leds[button] = CRGB(R,G,B);
    FastLED.show();
  }
 ~Led(){};
};
