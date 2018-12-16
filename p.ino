bool DEBUG = true;
int responseTime = 10;
String ssid = "AP 901", password = "90135841775";
void setup() {
    Serial.begin(115200);
    Serial2.begin(115200);
}
void loop() {
    if(Serial.available() > 0){
        String cmd = readSerialMessage();
        Serial2.println(cmd);
        /*if(!find(cmd, "manda")) Serial2.println(cmd);
        if(find(cmd, "AT"))
            Serial.print("Hey, Esp\n");
        if(find(cmd, "manda"))*/
//            postToEsp8266("192.168.0.21", "Hello :)", responseTime);
    }
    if(Serial2.available()){
        String ans = readEsp8266();
        Serial.println(ans);
        /*
        if(find(ans, "OK"))
            Serial.print("Hey... funfou :)\n");
        else if(find(ans, ">"))
            sendToWiFi("<h1>Hello</h1><h2>World</h2>", responseTime, DEBUG);
        else*/
    }
}

/*Author: Unknown
 * Purpose: Send a command to Esp8266
 */
String sendToWiFi(String command, const int timeout, boolean debug){
    String response = "";
    Serial2.println(command);
    long int time = millis();
    while((time + timeout) > millis()){
        while(Serial2.available()>0){
            char c = Serial2.read();
            response += c;
        }
    }
    if(debug)
        Serial.println(response);
    return response;
}


/*Author: Unknown
 * Purpose: Read a mesage of Esp8266
 */
String readEsp8266(){
    char string[100];
    int index_count = 0; 
    while(Serial2.available()>0){
        string[index_count] = Serial2.read();
        index_count++;
        string[index_count] = '\0';
        delay(1);
    }
    String str(string);
    str.trim();
    return str;
}


/*Author: Unknown
 * Purpose: Read a mesage of Arduino serial
 */
String readSerialMessage(){
    char value[100];
    int index_count = 0;
    while(Serial.available()>0){
        value[index_count] = Serial.read();
        index_count++;
        value[index_count] = '\0';
        delay(1);
    }
    String str(value);
    str.trim();
    return str;
}
