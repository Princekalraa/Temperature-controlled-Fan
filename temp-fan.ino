#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define fanPin 3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(fanPin, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  if (temperature > 25.0) {
    digitalWrite(fanPin, HIGH);
    Serial.println("Fan turned ON");
  } else {
    digitalWrite(fanPin, LOW);
    Serial.println("Fan turned OFF");
  }
  
  delay(2000);
}
