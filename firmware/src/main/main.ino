#include "xiao_wio_sx1262.h"
#include "uart.h"
#include "command_dispatcher.h"

void setup() {

  UART::begin(115200);

}

void loop() {

  if(UART::available()){
    String cmd = UART::readLine();
    String response = COMMAND_DISPATCHER::execute(cmd);
    UART::println(response);
  }
  
}
