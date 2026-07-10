#ifndef UART_H
#define UART_H

#include <Arduino.h>

namespace UART
{
    void begin(uint32_t baudrate);

    bool available();

    String readLine();

    void print(String msg);

    void println(String msg);
}

#endif