#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
char auth[] = "Token"; //Enter the Auth code which was send by Blink
char ssid[] = "WiFi";  //Enter your WIFI Name
char pass[] = "Password";  //Enter your WIFI Password

#define DHTPIN D4         // Digital pin of your choice
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

SimpleTimer timer;
void sendSensor() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature
}
void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  // Setup a function to be called every second
  timer.setInterval(500, sendSensor);
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}
