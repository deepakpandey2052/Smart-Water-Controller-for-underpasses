#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e2b74b7e82064427a3010aaae7f1d952";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Hax";
char pass[] = "micromax";

int sensorValue;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

Blynk.begin(auth, ssid, pass);
pinMode(D1,OUTPUT);
pinMode(D0,INPUT);
}

void loop() {

   Blynk.run();
  // put your main code here, to run repeatedly:

  //sensorData = analogRead(A0); //reading the sensor on A0
   //sending to Blynk
  int sensorValue = digitalRead(D0);
Serial.println(sensorValue);

//delay(500);
if (sensorValue == 1)
{
  Serial.println("WATER DETECTED");
  //Blynk.virtualWrite(V5,sensorValue);
  Blynk.virtualWrite(V5,"Water Overflow");
 // Blynk.virtualWrite(V5,);
  }
  //while(sensorValue!=1)
  
 else if(sensorValue!=1){
  Serial.println("NO WATER");
  //Blynk.virtualWrite(V5,sensorValue);
   Blynk.virtualWrite(V5,"No Water is here");
 }
/*
digitalWrite(D1,HIGH);
delay(1000);
digitalWrite(D1,LOW);
delay(1000);*/

}






