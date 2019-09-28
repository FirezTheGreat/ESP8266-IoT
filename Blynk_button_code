#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Token by blynk";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WiFi Name";
char pass[] = "Password";
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
  analogWrite(D0,pinValue);
}
void setup()
{
  pinMode(D0,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
}
