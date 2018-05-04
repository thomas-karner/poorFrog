#include <DHT.h>


#define DHT_A_PIN 11
#define DHT_A_TYPE DHT22
DHT dhtA(DHT_A_PIN, DHT_A_TYPE);

float hum;
float temp;
void setup() {
  Serial.begin(115200);
  dhtA.begin();
}

void loop() {
  temp = dhtA.readTemperature();
  hum = dhtA.readHumidity();

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C");
  Serial.println();
  //Serial.print(\n\r);
  delay(2000);
  

}

