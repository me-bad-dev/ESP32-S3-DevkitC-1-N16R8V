#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1
CRGB leds[NUM_LEDS];

void setup() 
{
  Serial.begin(115200);
  Serial.print("Avalible flash size: ");
  Serial.print(ESP.getFlashChipSize()/1024/1024);
  Serial.println("MB");

  FastLED.addLeds<NEOPIXEL, 48>(leds, NUM_LEDS);
}

void loop() 
{
  /*
  neopixelWrite(RGB_BUILTIN,RGB_BRIGHTNESS,0,0); // Red
  delay(1000);
  neopixelWrite(RGB_BUILTIN,0,RGB_BRIGHTNESS,0); // Green
  delay(1000);
  neopixelWrite(RGB_BUILTIN,0,0,RGB_BRIGHTNESS); // Blue
  delay(1000);
  neopixelWrite(RGB_BUILTIN,0,0,0); // Off / black
  delay(1000);
  */

  for (int i=0; i<=255;i++) 
  {
    leds[0] = CHSV( i, 255, 100);
    FastLED.show();
    delay(16);
  }
}