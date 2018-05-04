#include <GUVA-S12SD.h>
GUVAS12SD uv(A0);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float mV = uv.read();

  Serial.print(mV);
  Serial.print(" (mV)");
  Serial.println();

  
  float uv_index = uv.index(mV);
  Serial.print("Idx: ");
  Serial.print(uv_index);
  Serial.println();

}
