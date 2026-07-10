#include "uart.h"


namespace UART
{

void begin(uint32_t baudrate)
{
    Serial.begin(baudrate);

    delay(500);

    Serial.println("; SX1262-LAB");
    Serial.println("; UART Ready");
}


bool available()
{
    return Serial.available();
}


String readLine()
{
    String data = Serial.readStringUntil('\n');
    data.trim();

    return data;
}


void print(String msg)
{
    Serial.print(msg);
}


void println(String msg)
{
    Serial.println(msg);
}

}