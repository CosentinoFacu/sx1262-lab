#include "uart.h"
#include "parser.h"

void setup() {

  UART::begin(115200);

}

void loop() {

  if(UART::available()){
    String cmd = UART::readLine();
    String response = PARSER::execute(cmd);
    UART::println(response);
  }
  
}
