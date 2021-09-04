#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h> 
#include <UniversalTelegramBot.h> 
#include <ArduinoJson.h> 

int trigPin = 5; // DI Pin of nodeMCU
int echoPin = 4; //D2 Pin nodeMCU
float pingTime; 
float targetDistance; 
float speedOfSound = 340; 

#define BOTtoken "xxxxxxx" // telegram bot token
#define CHAT_ID "xxxxxx" 
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client); 
const char* ssid = "xxxxxxx"; //ssid of the wifi network connected to nodeMCU
const char* password = "xxxx"; //password of the wifi network connected to nodeMCU

void setup()
{
    Serial.begin(115200); 
    client.setInsecure(); 
    WiFi.begin(ssid, password); 
    pinmode(trigPin, OUTPUT); 
    pinmode(echoPin, INPUT); 
    pinmode(16, OUTPUT); 
}

void loop(){
    digitalWrite(trigPin, LOW); 
    delay(50);
    digitalWrite(trigPin, HIGH); 
    delay(50); 
    digltalWrite(trigPin, LOW); 
    pingTime=pulseIn(echoPin, HIGH);
    targetDistance = speedOfSound * pingTime / 10000;
    targetDistance /= 2;
    Serial.print("An object is found at ");
    Serial.println(targetDistance);

    if(targetDistance < 20){
        bot.sendMessage(CHAT_ID, "Intruder detected", "");
        digitalWrite(16, HIGH);
    }
    else{
        digitalWrite(16, LOW);
    }
}
