int temout = 8;
int temin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(temin));
  delay(100);

}
