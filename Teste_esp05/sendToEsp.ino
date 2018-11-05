/*Author: Unknown
 * Purpose: Send a command to Esp8266
 */
String sendToWiFi(String command, const int timeout, boolean debug){
    String response = "";
    Serial1.println(command);
    long int time = millis();
    while((time + timeout) > millis()){
        while(Serial1.available()>0){
            char c = Serial1.read();
            response += c;
        }
    }
    if(debug)
        Serial.println(response);
    return response;
}
