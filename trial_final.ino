

int ledPin = 13;  // use the built in LED on pin 13 of the Uno
int state = 0;
int flag = 0;        // make sure that you return the state only once
  

void setup() {
    // sets the pins as outputs:
    pinMode(ledPin, HIGH);
    digitalWrite(ledPin, LOW);
     
    Serial.begin(9600); // Default connection rate for my BT module


    
}

void loop() {

     //if some data is sent, read it and save it in the state variable
    if(Serial.available() > 0){
      state = Serial.read();
      flag = 0;
      
    }
   else if(Serial.available() == 0) {
     digitalWrite(ledPin,LOW);
   }
    // if the state is 0 the led will turn off
    if (state == '0') {
        digitalWrite(ledPin,LOW);
        
         if(flag == 0){
          Serial.println("Welcome, you are connected with your Kid!\n");
          
          
          //digitalWrite(ledpin,HIGH);
          //delay(500);
          //digitalWrite(ledpin,LOW);
          //delay(500);
          flag = 1;
        }
    }
    else if(state == '2') {     // finds out if I am still connected to the kid
    digitalWrite(ledPin,LOW);
    if(flag ==0) {
      Serial.println("Your kid is in range\n");
      flag = 1;
     }
    }
    // if the state is 1 the led will turn on
    else if(state == '1') {

      delay(15000);
       //digitalWrite(ledPin,LOW);
        
        digitalWrite(ledPin,HIGH);
      }        
        if(flag == 0){
          Serial.println("");
          
          flag = 1;
        }
        }
    


