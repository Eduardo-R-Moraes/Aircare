/* libraries */
#include "DHT.h"


/* constants */
#define DHTPIN 2
#define DHTTYPE DHT11
#define RELEPIN 4


/* variables */
DHT dht(DHTPIN, DHTTYPE);
float humidity;


void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  pinMode(RELEPIN, OUTPUT);

  dht.begin();
}

void loop() {
  delay(2000);
  humidity = dht.readHumidity();

  if(isnan(humidity)) {
    Serial.println("DHT not working!");
  }

  else {
    Serial.print(humidity);
    Serial.println("%");
  }

  if(humidity > 50) {
    digitalWrite(RELEPIN, HIGH);
  }

  else {
    digitalWrite(RELEPIN, LOW);
  }
}
