#include "command_core.h"

namespace COMMAND_CORE
{

String execute(String command)
{
    command.trim();
    command.toUpperCase();

    //---------------------------------------------------------
    // *IDN?
    //---------------------------------------------------------
    if(command == "*IDN?")
    {
        return "SX1262-LAB,ESP32-S3,FW:0.1";
    }
    
    //---------------------------------------------------------
    // PING
    //---------------------------------------------------------
    if(command == "PING")
    {
        return "PONG";
    }

    //---------------------------------------------------------
    // HELP
    //---------------------------------------------------------
    if(command == "HELP")
    {
        return
            "Available commands:\r\n"
            "  *IDN?\r\n"
            "  HELP\r\n"
            "  PING";
    }
    
    //---------------------------------------------------------
    // Unknown command
    //---------------------------------------------------------
    return "ERROR: UNKNOWN COMMAND";
}

}