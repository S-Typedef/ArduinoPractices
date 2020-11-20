int bee = 8;
int tones0[7] = {147,165,175,196,221,248,278};
int tones1[7] = {294,330,350,393,441,495,556};
int tones2[7] = {589,661,700,786,882,990,1112};
// 1 2 3 4 5 6 7 8
void setup() {
  // put your setup code here, to run once:
  pinMode(bee,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<3;i++) {
    //tone(bee,tones0[i],0);
//    noTone(70);
    //delay(100);
    
    tone(bee,tones1[i],500);
    noTone(70);
    delay(100);
//    
     //tone(bee,tones2[i],0);
//    noTone(70);
     //delay(100);
  }
}
