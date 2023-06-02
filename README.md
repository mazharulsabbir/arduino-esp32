To communicate with the SIM800 module on the LilyGO ESP32 development board, you can use AT commands through the serial interface. Here are some common AT commands for SIM800 module:

1. **Check SIM Card Status**: Checks if the SIM card is inserted and registered to the network.

   ```
   AT+CPIN?
   ```

2. **Set SMS Text Mode**: Sets the SMS mode to text mode.

   ```
   AT+CMGF=1
   ```

3. **Send SMS**: Sends an SMS message to a specified phone number.

   ```
   AT+CMGS="<phone_number>"
   <message>
   Ctrl+Z
   ```

   Replace `<phone_number>` with the recipient's phone number and `<message>` with the content of the SMS.

4. **Read SMS**: Reads the content of an SMS message at a specific index.

   ```
   AT+CMGR=<index>
   ```

   Replace `<index>` with the index number of the SMS message you want to read.

5. **Delete SMS**: Deletes an SMS message at a specific index.

   ```
   AT+CMGD=<index>
   ```

   Replace `<index>` with the index number of the SMS message you want to delete.

6. **List All SMS Messages**: Lists all received SMS messages.

   ```
   AT+CMGL="ALL"
   ```

   This command will return a list of SMS messages along with their index numbers and other details.

These are just a few examples of commonly used AT commands. The SIM800 module supports many more AT commands for various functionalities. You can refer to the SIM800 AT Command Manual for a complete list of supported commands and their usage. Additionally, the LilyGO ESP32 development board may have specific pin configurations for the SIM800 module, so consult the board's documentation for more information on hardware setup and configuration.
