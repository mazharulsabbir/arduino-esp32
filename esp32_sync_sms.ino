#define SIM800L_AXP192_VERSION_20200327

#include "utilities.h"

#define TINY_GSM_MODEM_SIM800 // sim800 and sim7000 are very identical, no sim7000 reset tool yet but sim800 works

#include <TinyGsmClient.h>


// Set serial for AT commands (to the module)
#define SerialAT Serial1

// See all AT commands, if wanted
#define DUMP_AT_COMMANDS

#ifdef DUMP_AT_COMMANDS
#include <StreamDebugger.h>    // if enabled it requires the streamDebugger lib
StreamDebugger debugger(SerialAT, Serial);
TinyGsm modem(debugger);
#else
TinyGsm modem(SerialAT);
#endif

bool reply = false;

void setup()
{
  // Set console and modem baud rate
  Serial.begin(115200);

  delay(10);

  setupModem();

  // Set GSM module baud rate and UART pins
  SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);

  Serial.println("**Init**");

  SerialAT.println("AT");
  SerialAT.println("AT+CMGF=1"); // Sets the SMS mode to text mode.

  Serial.println("**Done!**\n");
}

void loop()
{
  while (SerialAT.available()) {
    String buff = SerialAT.readString();
    Serial.println(buff);
  }
  while (Serial.available()) {
    SerialAT.write(Serial.read());
  }
}

void readAllMsgContent() {
  //  read all msg
  SerialAT.println("AT+CMGL=\"ALL\"");
}

void readMsgContent(int index) {
  //  read sms by id
  SerialAT.println("AT+CMGR=" + index);
}
