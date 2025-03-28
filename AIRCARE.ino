/* libs */
#include "DHT.h"


/* constants */
#define DHTPIN 2
#define DHTTYPE DHT11
#define RELEPIN 4


/* variables */
DHT dht(DHTPIN, DHTTYPE);
float humidity;
float humidityGoal;


void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  pinMode(RELEPIN, OUTPUT);
}

void loop() {
  delay(2000);
  humidityGoal = 50;
  humidity = dht.readHumidity();

  /* Humidity reading */
  if(isnan(humidity)) {
    Serial.println("DHT not working!");
  }

  else {
    Serial.print(humidity);
    Serial.println("%");
  }

  /* Rele logic */
  if(humidity < humidityGoal) {
    digitalWrite(RELEPIN, HIGH);
  }

  else {
    digitalWrite(RELEPIN, LOW);
  }
}
