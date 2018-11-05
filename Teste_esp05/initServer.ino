/*Author: caelumLaron
 * Purpose: Initiate the principal funcs of Esp
 */
void initMasterEsp(){
    sendToWiFi("AT+CIFSR", responseTime, DEBUG);
    delay(5000);
    sendToWiFi("AT+CIPMUX=1", responseTime, DEBUG);
    delay(5000);
    //sendToWiFi("AT+CIPSERVER=1,80", responseTime, DEBUG);
    //delay(100);
}
