#include "FastLED.h"

#define PIN 6
#define NUM_LEDS 60

CRGBArray<NUM_LEDS> leds;
uint8_t color[NUM_LEDS];
uint8_t oldColor[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN> (leds, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CHSV(20,255,255);
    oldColor[i] = 32;
  }
  for (int i = 38; i < 45; i++){
    leds[i] = CHSV(0,255,255);
    oldColor[i] = 0;
  }
  for (int i = 16; i < 27; i++){
    leds[i] = CHSV(200,255,255);
    oldColor[i] = 200;
  }
}

void loop() {
  setLedFlame(0,5);
  //setLedFlame(16,19);
  setLedFlame(45,59);
  FastLED.show();
  delay(50); 
}

void setLedFlame(int firstLED,int lastLED){
  for (int i = firstLED; i < (lastLED+1); i++){
    if (!color[i] || oldColor[i]==color[i]){
      color[i]= randomFlame();
    }else{
      int n = color[i] > oldColor[i] ? 1 : -1;
      oldColor[i] = oldColor[i] + n;
      leds[i] = CHSV(oldColor[i],255,255);
    }
  }
}

int randomFlame(){
  int r = rand() % 20;
  if(r> 13){
    return 0;
  }else if(r>9){
    return 1;
  }else if(r > 6){
    return 3;
  }else if(r>1){
    return 2;
  }else{
    return 10;
  }
}
