#include<IRremote.h>
int RECV_PIN = 11;
int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=6;
int led6=7;
long on1 = 0x00ffa25d;
long off1 = 0x00ffe01f;
long on2 = 0x00ff629d;
long off2 = 0x00ffa857;
long on3 = 0x00ffe21d;
long off3 = 0x00ff906f;
long on4 = 0x00ff22dd;
long off4 = 0x00ff6897;
long on5 = 0x00ff02fd;
long off5 = 0x00ff9867;
long on6 = 0x00ffc23d;
long off6 = 0x00ffb04f;

IRrecv irrecv(11);
decode_results results;

void dump(decode_results *results){
  int count = results->rawlen;
  if(results->decode_type==UNKNOWN){
    Serial.println("Could not decode message");
  }
  else{
    if(results->decode_type==NEC){
      Serial.print("Decode NEC:");
    }
    else if(results->decode_type==SONY){
      Serial.print("Decode SONY:");
    }else if(results->decode_type==RC5){
      Serial.print("Decode RC5:");
    }else if(results->decode_type==RC6){
      Serial.print("Decode RC6:");
    }
    Serial.print(results->value,HEX);
    Serial.print("(");
    Serial.print(results->bits,DEC);
    Serial.print("bits)");
  }
  Serial.print("Raw(");
  Serial.print(count,DEC);
  Serial.print("):");
  for(int i=0;i<count;i++){
    if((i%2)==1){
      Serial.print(results->rawbuf[i]*50,DEC);
    }
    else
    {
      Serial.print(-(int)results->rawbuf[i]*50,DEC);
    }
    Serial.print(" ");
   }
}

void setup()
{
  pinMode(RECV_PIN,INPUT);
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(led3,OUTPUT); 
  pinMode(led4,OUTPUT); 
  pinMode(led5,OUTPUT); 
  pinMode(led6,OUTPUT); 
  pinMode(13,OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn();
}
int on = 0;
unsigned long last = millis();
void loop()
{
  if(irrecv.decode(&results))
  {
    if(millis()-last>250){
      on = !on;
      digitalWrite(8,on?HIGH:LOW);  
      digitalWrite(13,on?HIGH:LOW);  
      dump(&results);
    }
    if(results.value==on1)
      digitalWrite(led1,HIGH);  
    if(results.value==off1)
      digitalWrite(led1,LOW); 

    if(results.value==on2)
      digitalWrite(led2,HIGH),Serial.println("value is avaiable");  
    if(results.value==off2)
      digitalWrite(led2,LOW),Serial.println("value is unavaiable");   
      
      if(results.value==on3)
      digitalWrite(led3,HIGH);  
    if(results.value==off3)
      digitalWrite(led3,LOW); 
      
      if(results.value==on4)
      digitalWrite(led4,HIGH);  
    if(results.value==off4)
      digitalWrite(led4,LOW); 
      
      if(results.value==on5)
      digitalWrite(led5,HIGH);  
    if(results.value==off5)
      digitalWrite(led5,LOW); 
      
      if(results.value==on6)
      digitalWrite(led6,HIGH);  
    if(results.value==off6)
      digitalWrite(led6,LOW); 
      
    last = millis();
    irrecv.resume();
  }



}  
