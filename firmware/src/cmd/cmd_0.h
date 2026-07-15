#ifndef CMD_0_H
#define CMD_0_H

#include <RadioLib.h>

struct LoRaConfig
{
    float frequency;
    float bandwidth;
    uint8_t spreadingFactor;
    uint8_t codingRate;
    uint8_t syncWord;
    int8_t power;
    uint16_t preambleLength;
};

String cmd_init(SX1262& radio);

String cmd_status();

#endif