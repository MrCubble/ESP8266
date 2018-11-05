bool DEBUG = true;
int responseTime = 10;
String ssid = "AP 901", password = "90135841775";
void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);
    //connectToWiFi(ssid, password);
    initMasterEsp();
    delay(10000);
    int i = 0;
    while(i < 20){
        postToEsp8266("192.168.0.18", "Hello :)", responseTime);
        i++;
        delay(5000);
    }
}
void loop() {
    if(Serial.available() > 0){
        String cmd = readSerialMessage();
        if(!find(cmd, "manda")) Serial1.println(cmd);
        if(find(cmd, "AT"))
            Serial.print("Hey, Esp\n");
        if(find(cmd, "manda"))
            postToEsp8266("192.168.0.21", "Hello :)", responseTime);
    }
    if(Serial1.available()>0){
        String ans = readEsp8266();
        if(find(ans, "OK"))
            Serial.print("Hey... funfou :)\n");
        else if(find(ans, ">"))
            sendToWiFi("<h1>Hello</h1><h2>World</h2>", responseTime, DEBUG);
        else
            Serial.println(ans);
    }
}
