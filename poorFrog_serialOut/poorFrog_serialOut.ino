#include <GUVA-S12SD.h>
#include <DHT.h>

#define DHT_A_PIN 11
#define DHT_A_TYPE DHT22

GUVAS12SD uv(A0);
DHT dhtA(DHT_A_PIN, DHT_A_TYPE);


//UV GUVA-S12SD
float uv_mV;
float uv_idx;

//Temp & Hum DHT22
float humA;
float tempA;

//Counter
int i = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dhtA.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  tempA = dhtA.readTemperature();
  humA = dhtA.readHumidity();
  uv_mV = uv.read();
  uv_idx = uv.index(uv_mV);
  
  printHeader();
  printDHT_A();
  printUV();
  printFooter();
  //Serial.print(\n\r);
  delay(200000);
  i += 1;
}
void printHeader(){
  Serial.print("*******measurement #");
  Serial.print(i);
  Serial.println("*******");
}
void printFooter() {
  Serial.println("***************************");
}
void printDHT_A() {
  
  Serial.print("Temperature: ");
  Serial.print(tempA);
  Serial.print(" C");
  Serial.println();
  Serial.print("Humidity: ");
  Serial.print(humA);
  Serial.println();
}

void printUV() {
  Serial.print("UV Index: ");
  Serial.print(uv_idx);
  Serial.print(" = (");
  Serial.print(uv_mV);
  Serial.print("mV)");
  Serial.println();

  
}


