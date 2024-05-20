#include "Adafruit_Neopixel.h"
#define NUM_LEDS        16
#define LED_PIN         15


Adafruit_NeoPixel leds(NUM_LEDS,LED_PIN,NEO_GRB + NEO_KHZ800);

int bright = 255;

void LED_setup()
{
    leds.begin();
    leds.setBrightness(bright);
    leds.show();
}

void LED_test_rainbow()
{
     for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256)
     {
        for(int i=0; i<leds.numPixels(); i++) {
            long pixelHue = firstPixelHue + (i * 65536L / leds.numPixels());
            leds.setPixelColor(i, leds.gamma32(leds.ColorHSV(pixelHue)));
            }
        delay(9);
        leds.show();
     }
}
void LED_test_red()
{
    for(int i=0;i<leds.numPixels();i++)
    {
        leds.setPixelColor(i,0xff0000);
        leds.show();
    }
}
void LED_test_blue()
{
    for(int i=0;i<leds.numPixels();i++)
    {
        leds.setPixelColor(i,0xff);
        leds.show();
    }
}
void LED_test_green()
{
    for(int i=0;i<leds.numPixels();i++)
    {
        leds.setPixelColor(i,0xff00);
        leds.show();
    }
}
