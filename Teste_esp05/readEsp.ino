/*Author: Unknown
 * Purpose: Read a mesage of Esp8266
 */
String readEsp8266(){
    char string[100];
    int index_count = 0; 
    while(Serial1.available()>0){
        string[index_count] = Serial1.read();
        index_count++;
        string[index_count] = '\0';
        delay(1);
    }
    String str(string);
    str.trim();
    return str;
}
