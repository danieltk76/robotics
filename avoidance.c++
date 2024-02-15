
int random2;
int a;
int a1;
int a2;
#define ML_Ctrl 13 
#define ML_PWM 11   
#define MR_Ctrl 12  
#define MR_PWM 3  

#define Trig 5 
#define Echo 4  
int distance;
#define servoPin 9 
int pulsewidth;

void Car_front()
{
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,200);
  digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,200);
}
void Car_back()
{
  digitalWrite(MR_Ctrl,HIGH);
  analogWrite(MR_PWM,200);
  digitalWrite(ML_Ctrl,HIGH);
  analogWrite(ML_PWM,200);
}
void Car_left()
{
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,255);
  digitalWrite(ML_Ctrl,HIGH);
  analogWrite(ML_PWM,255);
}
void Car_right()
{
  digitalWrite(MR_Ctrl,HIGH);
  analogWrite(MR_PWM,255);
  digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,255);
}
void Car_Stop()
{
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,0);
  digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,0);
}


void procedure(int myangle) {
  for (int i = 0; i <= 50; i = i + (1)) {
    pulsewidth = myangle * 11 + 500;
    digitalWrite(servoPin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servoPin,LOW);
    delay((20 - pulsewidth / 1000));
  }
}

float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00; 
  delay(10);
  return distance;
}

void setup(){
  pinMode(servoPin, OUTPUT);
  procedure(90); 
  
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
}
void loop(){
  random2 = random(1, 100);
  a = checkdistance();  
  
  if (a < 20)
  {
      Car_Stop(); 
      delay(500); 
      procedure(160);  
      for (int j = 1; j <= 10; j = j + (1)) { 
        a1 = checkdistance();  
      }
      delay(300);
      procedure(20);
      for (int k = 1; k <= 10; k = k + (1)) {
        a2 = checkdistance(); 
      }
      
      if (a1 < 50 || a2 < 50)  
      {
        if (a1 > a2)   
        {
          procedure(90);      
Car_left();  
          delay(500); 
          Car_front(); 
        } 
        else 
        {
          procedure(90);
          Car_right(); 
          delay(500);
          Car_front();  
        }
      } 
      else  
      {
        if ((long) (random2) % (long) (2) == 0)  
        {
          procedure(90);
          Car_left();
          delay(500);
          Car_front(); 
        } 
        else 
        {
          procedure(90);
          Car_right();
          delay(500);
          Car_front(); 
       }
     }
  } 
  else 
  {
      Car_front(); //go front
  }
}

