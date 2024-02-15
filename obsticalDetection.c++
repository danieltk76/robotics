const int SENSOR_PIN = 8;

int lastState = HIGH;
int currentState;


void setup()
{
    Serial.Begin(9600);

    pinMode(SENSOR_PIN, INPUT);

}

void loop()
{
    currentState = digitalRead(SENSOR_PIN);

    if (lastState == HIGH && currentState == LOW)
        Serial.println("Obstical detected");
    else if (lastState == LOW && currentState == HIGH)
        Serial.println("Obstical cleared");

    delay(100);
    lastState = currentState;

}