#include<HX711.h>
HX711 hx(9,10,128,0.003506);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hx.set_offset(26110);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  double sum0=0;
  double sum1=0;
  for(int i=0;i<10;i++){
    sum0+=hx.read();
    sum1+=hx.is_ready();
  }
  Serial.print(sum0/10);
  Serial.print(" ");
  Serial.println(sum1/10);
}
