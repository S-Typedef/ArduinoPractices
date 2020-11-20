#define uchar unsigned char
#define uint unsigned int
int BEEP=8;
//生日快乐歌的音符频率表，不同频率由不同的延时来决定
int SONG_TONE[]={212,212,190,212,159,169,212,212,190,212,142,159,
                                                212,212,106,126,159,169,190,119,119,126,159,142,159,0};
//生日快乐歌节拍表，节拍决定每个音符的演奏长短
int SONG_LONG[]={9,3,12,12,12,24,9,3,12,12,12,24,
9,3,12,12,12,12,12,9,3,12,12,12,24,0};
//延时
void DelayMS(uint x)
{
        uchar t;
        while(x--) for(t=0;t<120;t++);
}
//播放函数
void PlayMusic()
{
        uint i=0,j,k;
        while(SONG_LONG[i]!=0||SONG_TONE[i]!=0)
        {        //播放各个音符，SONG_LONG为拍子长度
                for(j=0;j<SONG_LONG[i]*20;j++)
                {
                        digitalWrite(BEEP,HIGH);
                        //SONG_TONE延时表决定了每个音符的频率
                        for(k=0;k<SONG_TONE[i]/3;k++);
                        digitalWrite(BEEP,LOW);
                }
                DelayMS(10);
                i++;               
        }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BEEP,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PlayMusic();
}
