int green_led = 4;
int red_led = 5;
int yellow_led = 6;
int btn_one = 11;
int btn_two = 12;
int btn_three = 13;

int trig = 8;
int echo = 9;
long lecture_echo;
long cm;

void setup()
{
    pinMode(green_led, OUTPUT);
    pinMode(red_led, OUTPUT);
    pinMode(yellow_led, OUTPUT);

    pinMode(btn_one, INPUT);
    pinMode(btn_two, INPUT);
    pinMode(btn_three, INPUT);

    pinMode(trig, OUTPUT);
    digitalWrite(trig, LOW);
    pinMode(echo, INPUT);

    Serial.begin(9600);
}

void greenSchema()
{
    digitalWrite(green_led, HIGH);
    delay(1000);
    digitalWrite(green_led, LOW);
    delay(1000);
}

void redSchema()
{
    digitalWrite(red_led, HIGH);
    delay(1000);
    digitalWrite(red_led, LOW);
    delay(1000);
}

void yellowSchema()
{
    digitalWrite(yellow_led, HIGH);
    delay(1000);
    digitalWrite(yellow_led, LOW);
    delay(1000);
}



void loop()
{
    digitalWrite(trig, HIGH);
    delayMicroseconds(10); // envoi d'une impulsion sur trig de 10 microsecondes
    digitalWrite(trig, LOW);
    lecture_echo = pulseIn(echo, HIGH);
    cm = lecture_echo / 58; // lecture_echo*340/(2*10000)
    Serial.print("Distance en cm : ");
    Serial.println(cm);
    delay (1000);

    if (cm < 10)
    {
        redSchema();
    }
    else if (cm < 20)
    {
        yellowSchema();
    }
    else
    {
        greenSchema();
    }
}


// Si le capteur ultrasonique détecte un objet à moins de 10 cm, la LED rouge s'allume.
// Si le capteur ultrasonique détecte un objet à moins de 20 cm, la LED jaune s'allume.
// Si le capteur ultrasonique détecte un objet à plus de 20 cm, la LED verte s'allume.