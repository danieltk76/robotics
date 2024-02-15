/*
 keyestudio Mini Tank Robot V2
 lesson 5
 Ultrasonic LED
 http://www.keyestudio.com
*/ 
int trigPin = 5;    
int echoPin = 4;    
long duration, cm, inches;
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 void loop() 
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     
  inches = (duration/2) / 74;   
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
if (cm>=2 && cm<=10)
digitalWrite(10, HIGH);
delay(1000);
digitalWrite(10, LOW);
delay(1000);
}
