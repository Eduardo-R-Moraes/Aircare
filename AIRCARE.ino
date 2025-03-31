/* libs */
#include "DHT.h"


/* constants */
#define DHTPIN 5
#define DHTTYPE DHT11
#define RELEPIN 4


/* variables */
DHT dht(DHTPIN, DHTTYPE);
float humidity;
float temperature;
float humidityGoal;


void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  pinMode(RELEPIN, OUTPUT);
}

void loop() {
  delay(3000);
  humidityGoal = 60;
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  /* Humidity reading */
  if(isnan(humidity) || isnan(temperature) || humidity > 95) {
    Serial.println("DHT failed!");
  }

  else {
    Serial.print(humidity);
    Serial.print("%\t");
    Serial.print(temperature);
    Serial.println("°C");
  }

  /* Rele logic */
  if(humidity < humidityGoal) {
    digitalWrite(RELEPIN, LOW);
  }

  else {
    digitalWrite(RELEPIN, HIGH);
  }
}