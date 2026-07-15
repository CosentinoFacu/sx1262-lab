#include "command_dispatcher.h"
#include "cmd_0.h"

namespace COMMAND_DISPATCHER
{

String execute(SX1262& radio, String command)
{
    command.trim();
    command.toUpperCase();

    //=============================================
    if(command == "*IDN?")
    {   
        String mgs;
        mgs += "-------------------------\r\n";
        mgs += "SX1262-LAB,ESP32-S3,FW:0.1\r\n";
        return mgs;
    }
    //=============================================
    if(command == "PING")
    {   
        String mgs;
        mgs += "-------------------------\r\n";
        mgs += "PONG\r\n";
        return mgs;
    }
    //=============================================
    if(command == "HELP")
    {   
        String mgs;
        mgs += "-------------------------\r\n";
        mgs += "Available commands:\r\n";
        mgs += "  ------- Sistema ----------\r\n";
        mgs += "  *IDN?\r\n";
        mgs += "  HELP\r\n";
        mgs += "  PING\r\n";
        mgs += "  ------- LoRa ----------\r\n";
        mgs += "  LORA:INIT\r\n";
        mgs += "  LORA:STATUS?\r\n";
        return mgs;
    }
    //=============================================
    if(command == "LORA:INIT")
    {   
        return cmd_init(radio);
    }
    //=============================================
    if(command == "LORA:STATUS?")
    {   
        return  cmd_status();
    }
    //=============================================
    return "ERROR: UNKNOWN COMMAND";
}

}