#include <Arduino.h>
#include "led.h"
#include "touch.h"
#include <Serial.h>
#include "debug_serial.h"

static int times = 0;

void setup()
{
    Serial_Setup();

    Serial.print("waiting...");
    //delay(10*1000);
    //LED_setup();
    //Touch_Setup();
    
}
void loop()
{
    /*for(int j =times;j/10==0;j++)
    {
        LED_test_red();
    }
    for(int j =times;j/20==0;j++)
    {
        LED_test_blue();
    }
    for(int j =times;j/30==0;j++)
    {
        LED_test_green();
    }
    delay(10);*/
    LED_test_rainbow();

    Serial.print("It runs ");
    Serial.print(" times!");
    Serial.print(times);
    times++;

    /*Serial.print("ready to initial caps\n");
    delay(10*1000);
    init_capa();
    Serial.print("Capa initial success\n");*/

    if(times/10 == 1000){
        Serial.print("Times 100k archieve\n");
        times = 0;
    }
}