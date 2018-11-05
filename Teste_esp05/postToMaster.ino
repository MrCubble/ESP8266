/*Author: caelumLaron
 *Purpose: Send a data to a Http page.
 */

String postToEsp8266(String andress, String txt, const int timeout){
    String response = "", len = "";
    sendToWiFi("AT+CIPSTART=4,\"TCP\",\"" + andress + "\",80", responseTime, DEBUG);
    delay(3000);
    len += txt.length();
    response = sendToWiFi("AT+CIPSEND=4," + len, responseTime, DEBUG);
    delay(10);
    if(find(response, ">"))
         sendToWiFi(txt, responseTime, DEBUG);
    delay(1000);
    if(DEBUG)
        Serial.println(response);
    sendToWiFi("AT+CIPCLOSE=5", responseTime, DEBUG);
    return response;
}
//AT+CIPSTART=4,"TCP","192.168.0.21",80 esse funfou
