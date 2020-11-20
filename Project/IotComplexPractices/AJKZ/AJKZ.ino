int buttonPin = 2;
int led  = 13;
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);
}
