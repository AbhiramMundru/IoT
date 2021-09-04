/*
The following code can be imported as example of NodeMCU Blynk sample
*/

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;
char *auth = ""; // auth code of the blynk project
char *ssid = ""; // ssid of wifi network
char *password = ""; // password of wifi network

void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, password);
    servo.attach(5); // pin number of pin where servo is connected
}

void loop()
{
    Blynk.run();
}

BLYNK_PRINT(V1)
{
    servo.write(param.asInt());
}