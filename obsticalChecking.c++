const int SENSOR_PIN = 8;

void setup()
{
    Serial.begin(9600);

    prinMode(SENSOR_PIN, INPUT);


}

void loop()
{
    int sttae = digitalRead(SENSOR_PIN);

    if (state == LOW)
        Serial.println("Obstical present");
    else    
        Serial.println("Obstical not present");

    delay(100); 
}