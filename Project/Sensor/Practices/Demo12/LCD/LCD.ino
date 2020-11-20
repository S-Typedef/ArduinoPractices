#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    lcd.begin(16, 2);             //???LCD1602
    lcd.print("Welcome to use!"); //????Welcome to use?
    delay(1000);                  //?? 1000ms
    lcd.clear();                  //????
}

void loop()
{

    lcd.setCursor(0, 0); //?�Z??????????�Z?00 ?
    lcd.print("Hello World!");

    lcd.setCursor(0, 1); //0 1???
    lcd.print("IoT Lab");
    delay(1000); //?? 1000ms
    lcd.setCursor(0, 0);
    lcd.print("Good Job!   ");
    delay(1000); //?? 1000ms
}