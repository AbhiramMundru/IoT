Arduino code:


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int trigPin=13;  // D7 Pin
int echoPin=12;  //D6 Pin
float pingTime;
float targetDistance;
float speedOfSound=340;

char auth[] = "tVibLYhKjpFtuaI5Hr927L5bhQH5pSRl";
char ssid[] = "Galaxy M21AAA2";
char pass[] = "mabtheuser";

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(A0, INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop()
{
  Blynk.run();
  Blynk.virtualWrite(V5, analogRead(A0)); 
  
  digitalWrite(trigPin,LOW);
  delay(50);
  digitalWrite(trigPin,HIGH);
  delay(50);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  targetDistance=speedOfSound*pingTime/10000;
  targetDistance=targetDistance/2;
  Blynk.virtualWrite(V6, targetDistance); 
  
}
