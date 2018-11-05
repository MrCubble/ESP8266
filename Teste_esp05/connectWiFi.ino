/*Auhtor: caelumLaron
 * Purpose: connect to wifi
 */
void connectToWiFi(String ssid, String password){
    sendToWiFi("AT+CWMODE=3", responseTime, DEBUG);
    delay(1000);
    String ans = sendToWiFi("AT+CWJAP=\"AP 901\",\"90135841775\"", responseTime, DEBUG);
    if(find(ans, "OK"))
        Serial.println("Connected sir!");
    delay(4000);
}
