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
