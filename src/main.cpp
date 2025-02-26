#include <Arduino.h>
#include <FastLED.h>

//Onboard addressable led config
#define NUM_LEDS 1
#define LED_DRIVER_PIN 48 //The initial board version uses GPIO48, whereas v1.1 uses GPIO38

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  Serial.print("Avalible flash size: ");
  Serial.print(ESP.getFlashChipSize()/1024/1024);
  Serial.println("MB");

  if (psramFound()) Serial.println("PSRAM: Found");
  else {
    Serial.println("PSRAM: Not found");
  }

  FastLED.addLeds<NEOPIXEL, LED_DRIVER_PIN>(leds, NUM_LEDS);
}

void loop() 
{
  /* Rainbow effect for onboard addressable RGBW LED */
  /* If the RGBW LED is not working, inspect the soldering pads on the board marked RGB, the pads need to be connected by soldering them together */

  for (int i=0; i<=255;i++) {
    leds[0] = CHSV( i, 255, 100);
    FastLED.show();
    delay(15);
  }
}
