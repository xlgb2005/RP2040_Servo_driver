#include <Arduino.h>
#include "RP2040_PWM_fix.h"
#include "OneButton.h"

RP2040_PWM* PWM_Instance;
int pwmpin= 26;
float freq = 330;

float minduty=16.7;
float maxduty=83.2;
float targetduty=30;
float stepdegrees=(83.2-16.70)/180*10;

bool initflag=false;
float i=20;

OneButton butup(3);
OneButton butdown(5);

void up();
void down();
void longup();
void longdown();
void initflagfuc();

void setup()
{
    PWM_Instance = new RP2040_PWM(pwmpin,freq, 50);
    
    //initflag = digitalRead(3);
    initflag = true;
    if(initflag){
        for (float ceta = minduty; ceta < maxduty; ceta=ceta+0.1)
           {
                PWM_Instance->setPWM(pwmpin,freq,ceta);
                delay(1);
            }
        for (float ceta = maxduty; ceta > targetduty; ceta=ceta-0.1)
            {
                PWM_Instance->setPWM(pwmpin,freq,ceta);
                delay(1);
            }
    }
    butup.reset();
    
    butup.attachClick(up);
    //butup.attachDuringLongPress(longup);
    butdown.attachClick(down);
    //butdown.attachDuringLongPress(longdown);
}

void loop()
{
    butup.tick();
    butdown.tick();
    PWM_Instance->setPWM(pwmpin,freq,targetduty);
    
    
    
   
    
}

void up(){
    if (targetduty<maxduty)
        {
            targetduty++;
        }
    }

void down(){
    if (targetduty>minduty)
        {
            targetduty--;
        }
    }

void longup(){
    if (butup.isLongPressed())
        {
            if (targetduty>minduty)
            {
                targetduty++;
            }
        }
    PWM_Instance->setPWM(pwmpin,freq,targetduty);
}
void longdown(){
    if (butdown.isLongPressed())
        {
            if (targetduty>minduty)
                {
                    targetduty--;
                }
        }
    PWM_Instance->setPWM(pwmpin,freq,targetduty);
}

void initflagfuc(){
    initflag=true;
    }