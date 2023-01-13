#define INPUT_PIN 28
#define OUTPUT_PIN 27 
#define GATE_PIN = 0

void setup()
{
    pinMode(INPUT_PIN, INPUT);
    pinMode(OUTPUT_PIN, OUTPUT);
    pinMode(GATE_PIN, INPUT);
}

bool high = false;

void sampleAndHold()
{
    if (!high && digitalRead(GATE_PIN) == HIGH) {
        high = true;
        analogWrite(OUTPUT_PIN, analogRead(INPUT_PIN));
    } 

    if (high && digitalRead(GATE_PIN) == LOW) {
        high = false;
    }
}

void loop()
{
    sampleAndHold();
}

