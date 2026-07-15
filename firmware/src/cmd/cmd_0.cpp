#include <Arduino.h>
#include "cmd_0.h"

// Configuración del sistema
static LoRaConfig config =
{
    .frequency = 915.0,
    .bandwidth = 125.0,
    .spreadingFactor = 7,
    .codingRate = 5,
    .syncWord = RADIOLIB_SX126X_SYNC_WORD_PRIVATE,
    .power = 10,
    .preambleLength = 8
};

String cmd_init(SX1262& radio)
{

    int state = radio.begin(
        config.frequency,
        config.bandwidth,
        config.spreadingFactor,
        config.codingRate,
        config.syncWord,
        config.power,
        config.preambleLength
    );

    String mgs;
    mgs += "-------------------------\r\n";

    if(state != RADIOLIB_ERR_NONE) {
        mgs += "ERROR: No se pudo inicializar el SX1262.\r\n";
        return mgs;
    } else {
        mgs += "SX1262 inicializado correctamente.\r\n"; 
        return mgs;      
    }
}

String cmd_status()
{

    String status;

    status += "-------------------------\r\n";

    status += "  FREQ: ";
    status += String(config.frequency);
    status += " MHz\r\n";


    status += "  BW: ";
    status += String(config.bandwidth);
    status += " kHz\r\n";


    status += "  SF: ";
    status += String(config.spreadingFactor);
    status += "\r\n";


    status += "  CR: ";
    status += String(config.codingRate);
    status += "\r\n";


    status += "  POWER: ";
    status += String(config.power);
    status += " dBm\r\n";


    status += "  PREAMBLE: ";
    status += String(config.preambleLength);
    status += "\r\n";


    return status;
}
