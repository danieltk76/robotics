
#define ML_Ctrl 13
#define ML_PWM 11 
#define MR_Ctrl 12  
#define MR_PWM 3   
void setup()
{ pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
}
void loop()
{ digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,100);
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,100);
//front 
  delay(2000);
  digitalWrite(ML_Ctrl,HIGH);
  analogWrite(ML_PWM,100);
  digitalWrite(MR_Ctrl,HIGH);
  analogWrite(MR_PWM,100);
//back
  delay(2000);
  digitalWrite(ML_Ctrl,HIGH);
  analogWrite(ML_PWM,100);
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,100);
//left
  delay(2000);
   digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,100);
  digitalWrite(MR_Ctrl,HIGH);
  analogWrite(MR_PWM,100);
//right
  delay(2000);
  analogWrite(ML_PWM,0);
  analogWrite(MR_PWM,0);
//stop
  delay(2000);
}
