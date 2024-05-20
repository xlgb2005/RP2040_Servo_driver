#include <Serial.h>

void Serial_Setup()
{
    Serial.begin(115200);
    Serial.print("Serial Port ok!");
}