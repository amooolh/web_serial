#include <Servo.h>

Servo myservo;  
int pos = 0;    

void setup() {
 Serial.begin(9600);
  myservo.attach(9); 
}


void loop() {
  
    String data=Serial.readString(); 
    if (data.indexOf("يمين") > -1){ 
     
      myservo.write(180);
     }
    else if (data.indexOf("يسار") > -1){ 
      myservo.write(0); 
      }
}
