int RECV_PIN = A0;        
IRrecv irrecv(RECV_PIN);   
decode_results results;   
void setup()  
	{  
      Serial.begin(9600);  
      irrecv.enableIRIn(); //Enable receiver
	}  
 void loop() {  
	  if (irrecv.decode(&results))
	  {  
	    Serial.println(results.value, HEX);
	    irrecv.resume(); 
	  }  
	  delay(100);  
	}  
