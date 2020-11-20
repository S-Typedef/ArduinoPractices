int counter = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  counter++;
  Serial.print(counter);
  Serial.print(":");
  Serial.print("Hello word");
  Serial.print("你好世界\n");
  delay(1000);
}
