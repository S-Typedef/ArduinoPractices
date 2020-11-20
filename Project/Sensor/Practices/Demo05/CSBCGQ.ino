#define Trig 2  //引脚Tring连接 IO D2
#define Echo 3  //引脚Echo连接 IO D3

float cm;   //距离变量
float temp; //
void setup(){
    Serial.begin(9600);
    pinMode(Trig,OUTPUT);
    pinMode(Echo,INPUT);
}
void loop(){
    //给Trig发送一个地高低的短时间脉冲，触发测距
    digitalWrite(Trig,LOW); //发送低电平
    delayMicroseconds(2);   //延时2us
    digitalWrite(Trig,HIGH);//发送高电平
    delayMicroseconds(10);  //延时10us
    digitalWrite(Trig,LOW); //发送低电平

    temp=float(pulseIn(Echo,HIGH)); //存储回波等待时间
    //pulseIn函数会等待引脚变为HIGH，开始计算时间，再等待变为LOW并停止计时

    //声速340m/s 即34000cm/1000000us == 34/1000
    //来回计算两次，除以二

    cm=(temp*17)/1000;  //脉冲长度
    Serial.print("Echo = ");
    Serial.print(temp); //串口输出等待时间的原始数据
    Serial.print(" | | Distance = ");
    Serial.print(cm);   //串口输出距离换算成cm
    Serial.println("cm");
    delay(100);
}