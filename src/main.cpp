#include <Arduino.h>
#include <FastLED.h>

//Onboard addressable led config
#define NUM_LEDS 1
#define LED_DRIVER_PIN 48 //The initial board version uses GPIO48, whereas v1.1 uses GPIO38

CRGB leds[NUM_LEDS];

void setup() 
{
  Serial.begin(115200);
  Serial.print("Avalible flash size: ");
  Serial.print(ESP.getFlashChipSize()/1024/1024);
  Serial.println("MB");

  FastLED.addLeds<NEOPIXEL, LED_DRIVER_PIN>(leds, NUM_LEDS);
}

void loop() 
{
  /* Rainbow effect for onboard addressable led */
  neopixelWrite(RGB_BUILTIN,RGB_BRIGHTNESS,0,0); 
  delay(1000);
  neopixelWrite(RGB_BUILTIN,0,RGB_BRIGHTNESS,0);
  delay(1000);
  neopixelWrite(RGB_BUILTIN,0,0,RGB_BRIGHTNESS); 
  delay(1000);
  neopixelWrite(RGB_BUILTIN,0,0,0);
  delay(1000);

  for (int i=0; i<=255;i++) 
  {
    leds[0] = CHSV( i, 255, 100);
    FastLED.show();
    delay(15);
  }
}
