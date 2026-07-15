#include "xiao_wio_sx1262.h"
#include "uart.h"
#include "command_dispatcher.h"

#include <RadioLib.h>

SX1262 radio = new Module(
    BOARD_LORA_NSS,
    BOARD_LORA_DIO1,
    BOARD_LORA_RESET,
    BOARD_LORA_BUSY
  );


void setup() {

  UART::begin(115200);

}

void loop() {

  if(UART::available()){
    String cmd = UART::readLine();
    String response = COMMAND_DISPATCHER::execute(radio,cmd);
    UART::println(response);
  }
  
}