#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include <Arduino.h>

#include <RadioLib.h>

namespace COMMAND_DISPATCHER
{
    String execute(SX1262& radio, String command);
}

#endif