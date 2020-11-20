int buttonPin = 2;
int led  = 13;
int ledState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  while(digitalRead(buttonPin)==HIGH)
  if(ledState == HIGH)
    digitalWrite(led,LOW),ledState = !ledState;
  else
    digitalWrite(led,HIGH),ledState = !ledState;
  delay(500);
}
