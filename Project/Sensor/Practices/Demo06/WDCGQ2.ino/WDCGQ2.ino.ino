unsigned char LED_0F[] = {
    //0    1    2    3    4    5    6    7    8    9    A    b    C    d
    //E    F
    0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
unsigned char LED[4]; //⭘�? LED�?4սᱮ⽪㕃ᆈ
int SCLK = 4;
int RCLK = 3;
int DIO = 2; //䘉䟼ᇊѹҶ䛓йњ�?
void setup()
{
    pinMode(SCLK, OUTPUT);
    pinMode(RCLK, OUTPUT);
    pinMode(DIO, OUTPUT); //䇙йњ㝊䜭ᱟ䗃ࠪ⣦ᘱ
}

void loop()
{
    LED[0] = 1;
    LED[1] = 2;
    LED[2] = 3;
    LED[3] = 4;
    while (1)
    {
        LED4_Display();
    }
}

void LED4_Display(void)
{
    unsigned char *led_table; // ḕ㺘ᤷ䪸
    unsigned char i;
    //ᱮ⽪�? 1ս
    led_table = LED_0F + LED[0];
    i = *led_table;
    LED_OUT(i);
    LED_OUT(0x01);
    digitalWrite(RCLK, LOW);

    digitalWrite(RCLK, HIGH);
    //ᱮ⽪�? 2ս
    led_table = LED_0F + LED[1];
    i = *led_table;
    LED_OUT(i);
    LED_OUT(0x02);
    digitalWrite(RCLK, LOW);
    digitalWrite(RCLK, HIGH);
    //ᱮ⽪�?3ս
    led_table = LED_0F + LED[2];
    i = *led_table;
    LED_OUT(i);
    LED_OUT(0x04);
    digitalWrite(RCLK, LOW);
    digitalWrite(RCLK, HIGH);
    //ᱮ⽪�?4ս
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
