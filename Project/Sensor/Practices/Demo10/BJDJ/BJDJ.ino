int Pin0 = 8;
int Pin1 = 9;
int Pin2 = 10;
int Pin3 = 11;
int _step = 0;
boolean dir = 1;      //1¡ı?,0??
int stepperSpeed = 1; //????,1ms§Ñ?

void setup()
{
    pinMode(Pin0, OUTPUT);
    pinMode(Pin1, OUTPUT);
    pinMode(Pin2, OUTPUT);
    pinMode(Pin3, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    switch (_step)
    {
    case 0:
        Serial.println("0");
        digitalWrite(Pin0, HIGH);
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, LOW);
        break;
    case 1:
        Serial.println("1");
        digitalWrite(Pin0, LOW);
        digitalWrite(Pin1, HIGH);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, LOW);
        break;
    case 2:
        Serial.println("2");
        digitalWrite(Pin0, LOW);
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, HIGH);
        digitalWrite(Pin3, LOW);
        break;
    case 3:
        Serial.println("3");
        digitalWrite(Pin0, LOW);
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, HIGH);
        break;
    default:
        digitalWrite(Pin0, LOW);
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, LOW);
        break;
    }

    if (dir)
    {
        _step++;
    }
    else
    {
        _step--;
    }

    if (_step > 3)
    {
        _step = 0;
    }

    if (_step < 0)
    {
        _step = 3;
    }
    delay(stepperSpeed);
}