double Fahrenheit(double celsius)
{
    return 1.8 * celsius + 32;
} //摄氏温度度转化为华氏温度

double Kelvin(double celsius)
{
    return celsius + 273.15;
} //摄氏温度转化为开氏温度

// 露点（点在此温度时，空气饱和并产生露珠）
double dewPoint(double celsius, double humidity)
{
    double A0 = 373.15 / (273.15 + celsius);
    double SUM = -7.90298 * (A0 - 1);
    SUM += 5.02808 * log10(A0);
    SUM += -1.3816e-7 * (pow(10, (11.344 * (1 - 1 / A0))) - 1);
    SUM += 8.1328e-3 * (pow(10, (-3.49149 * (A0 - 1))) - 1);
    SUM += log10(1013.246);
    double VP = pow(10, SUM - 3) * humidity;
    double T = log(VP / 0.61078); // temp var
    return (241.88 * T) / (17.558 - T);
}

// 快速计算露点，速度是5倍dewPoint()
double dewPointFast(double celsius, double humidity)
{
    double a = 17.271;
    double b = 237.7;
    double temp = (a * celsius) / (b + celsius) + log(humidity / 100);
    double Td = (b * temp) / (a - temp);
    return Td;
}

unsigned char LED_0F[] =
    {
        // 共阳数码管编码
        // 0 1 2 3 4 5 6 7 8 9 a b c d e f
        0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
unsigned char LED[4]; //用于 LED 的 4 位显示缓存
int SCLK = 4;
int RCLK = 3;
int DIO = 8;

#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 2
void LED4_Display();

void setup()
{
    pinMode(SCLK, OUTPUT);
    pinMode(RCLK, OUTPUT);
    pinMode(DIO, OUTPUT);
    Serial.begin(9600);
    Serial.println("DHT11 TEST PROGRAM ");
    Serial.print("LIBRARY VERSION: ");
    Serial.println(DHT11LIB_VERSION);
    Serial.println();
}
void loop()
{
    Serial.println("\n");
    int chk = DHT11.read(DHT11PIN);
    Serial.print("Read sensor: ");
    switch (chk)
    {
    case DHTLIB_OK:
        Serial.println("OK");
        break;
    case DHTLIB_ERROR_CHECKSUM:
        Serial.println("Checksum error");
        break;
    case DHTLIB_ERROR_TIMEOUT:
        Serial.println("Time out error");
        break;
    default:
        Serial.println("Unknown error");
        break;
    }
    //Serial.print("Humidity (%): ");
    //Serial.println((float)DHT11.humidity, 2);
    Serial.print("Temperature (oC): ");
    Serial.println((float)DHT11.temperature, 2);

    int a = DHT11.temperature;

    int k = a / 10;
    int g = (a - k * 10);
    Serial.println(k);
    Serial.println(g);

    //Serial.print("Temperature (oF): ");
    //Serial.println(Fahrenheit(DHT11.temperature), 2);
    //Serial.print("Temperature (K): ");
    //Serial.println(Kelvin(DHT11.temperature), 2);
    //Serial.print("Dew Point (oC): ");
    //Serial.println(dewPoint(DHT11.temperature, DHT11.humidity));
    //Serial.print("Dew PointFast (oC): ");
    //Serial.println(dewPointFast(DHT11.temperature, DHT11.humidity));

    LED[0] = 0;
    LED[1] = 0;
    LED[2] = g;
    LED[3] = k;

    dely();
}
void dely()
{
    int z = 1000;
    while (z > 1)
    {
        z--;
        LED4_Display();
    }
}
void LED4_Display(void)
{
    unsigned char *led_table; // 查表指针
    unsigned char i;
    //显示第 1 位
    led_table = LED_0F + LED[0];
    i = *led_table;
    LED_OUT(i);
    LED_OUT(0x01);
    digitalWrite(RCLK, LOW);
    digitalWrite(RCLK, HIGH);
    //显示第 2 位
    led_table = LED_0F + LED[1];
    i = *led_table;
    LED_OUT(i);
    LED_OUT(0x02);
    digitalWrite(RCLK, LOW);
    digitalWrite(RCLK, HIGH);
    //显示第 3 位
    led_table = LED_0F + LED[2];
    i = *led_table;
    LED_OUT(i);
    LED_OUT(0x04);
    digitalWrite(RCLK, LOW);
    digitalWrite(RCLK, HIGH);
    //显示第 4 位
    led_table = LED_0F + LED[3];
    i = *led_table;
    LED_OUT(i);
    LED_OUT(0x08);
    digitalWrite(RCLK, LOW);
    digitalWrite(RCLK, HIGH);
}

void LED_OUT(unsigned char X)
{
    unsigned char i;
    for (i = 8; i >= 1; i--)
    {
        if (X & 0x80)
        {
            digitalWrite(DIO, HIGH);
        }
        else
        {
            digitalWrite(DIO, LOW);
        }
        X <<= 1;
        digitalWrite(SCLK, LOW);
        digitalWrite(SCLK, HIGH);
    }
}
