#include "uart.h"

void setup() {

  UART::begin(115200);

}

void loop() {

  String cmd;

  if(UART::available()){
    cmd = UART::readLine();
    UART::println(cmd);
  }

}
