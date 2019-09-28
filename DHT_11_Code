#include "DHT.h"
#define DHTTYPE DHT11 // Analog Pin sensor is connected to
const int DHTPin = D7;
int led = D4; //your choice for digital pin
DHT dht(DHTPin, DHTTYPE); 
void setup(){
  dht.begin();
  Serial.begin(9600);
  pinMode(D4,OUTPUT);
  pinMode(D0, OUTPUT);
}
void loop(){
  //Start of Program 
    Serial.print("Current humidity = ");
   float h = dht.readHumidity();
   float t = dht.readTemperature();
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("*C  ");

    if(t<25)
    {
      digitalWrite(D4,HIGH); 
      digitalWrite(D0,LOW);
    }
   else
    {
        digitalWrite(D4,HIGH);
        digitalWrite(D0,LOW);
    }

    delay(2000);//Wait 5 seconds before accessing sensor again.
  //Fastest should be once every two seconds.
}// end loop(
