#include<Thread.h>
#define Do 1046  
#define Re 1175 
#define Mi 1318 
#define Fa 1397 
#define Sol 1568  
#define La 1760
#define Si 1967 
#define Do_h 2092 //2092 
#define Re_h 2350 //2350
#define Mi_h 2636 //2636
#define Fa_h 2794 //2794
#define Sol_h 3136  //3136
#define La_h 3420   //3420
#define Si_h 3934   //3934
int length;
int scale[] = {
    Sol, Sol, La, Sol, Do_h, Si,
    Sol, Sol, La, Sol, Re_h, Do_h,
    Sol, Sol, Sol_h, Mi_h, Do_h, Si, La,
    Fa_h, Fa_h, Mi_h, Do_h, Re_h, Do_h
    }; //生日歌曲谱
float durt[] =
    {
        0.5,0.5,1,1,1,1 + 1,
        0.5,0.5,1,1,1,1 + 1,
        0.5,0.5,1,1,1,1,1,0.5,
        0.5,1,1,1,1 + 1,
};//音长

int tonepin = 8; //用8号引脚
int led[] = {0,1,2,3,4,5,6,7,8};    //led使用0-7号引脚

void LED(){
  for(int i=0;i<8;i++){
    digitalWrite(led[i],HIGH);
    delay(70);
    digitalWrite(led[i],LOW);
    //delay(70);
  }
}

void PM(){
  for (int x = 0; x < length; x++)
    {
       tone(tonepin, scale[x]);
       digitalWrite(led[x%8],HIGH);
       delay(60 * durt[x]); //根据节拍调节延时
       digitalWrite(led[x%8],LOW);
       delay(30 * durt[x]);
       noTone(tonepin);
    }
}

Thread myLED=Thread();

void setup()
{
    pinMode(tonepin, OUTPUT);
    length = sizeof(scale) / sizeof(scale[0]); //计算长度
    for(int i = 0;i<8;i++){
      pinMode(led[i],OUTPUT);
    }

    myLED.onRun(LED);
}
void loop()
{
    myLED.run();
    PM();
    delay(250);
}
