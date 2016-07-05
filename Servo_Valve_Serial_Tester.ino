 //Controls a servo with the serial monitor
 
#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int pos = 0;
int servodata;

void setup()  {
 Serial.begin(9600);  
Serial.println("Ready");
Serial.println("Select 1, Valve OPEN ");
Serial.println("Select 2, Valve CLOSE ");
  myservo.attach(9);
  
}

void loop()   
{
  if (Serial.available() > 0)
  {
   servodata = Serial.read();
    
    if(servodata == '1') // Single Quote! This is a character.
    {
      Serial.println("Valve OPEN");
     for(pos = 0; pos < 100; pos += 1)    // goes from 0 degrees to '90' degrees 
  {                                       // in steps of 1 degree 
    myservo.write(pos);                   // tell servo to go to position in variable 'pos' 
    delay(2);                             // waits 2ms for the servo to reach the position 
  }
    }
    if(servodata == '2') // 
    {
      Serial.println("Valve CLOSE");
      for(pos = 100; pos>=1; pos-=1)
    {
      myservo.write(pos);
      delay(2);
    }
    }
    
    Serial.println();    // End the line

  
  }
}
