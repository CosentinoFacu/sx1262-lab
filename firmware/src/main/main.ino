#include "uart.h"
#include "command_core.h"

void setup() {

  UART::begin(115200);

}

void loop() {

  if(UART::available()){
    String cmd = UART::readLine();
    String response = COMMAND_CORE::execute(cmd);
    UART::println(response);
  }
  
}
