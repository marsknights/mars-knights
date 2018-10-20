

/*
  Into Robotics
*/

#define ir1 A0
#include <Servo.h>  //add '<' and '>' before and after servo.h

int servoPin = 9;

Servo servo;

int servoAngle = 0;   // servo position in degrees

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode (ir1, INPUT);

}


void loop()
{
  //control the servo's speed

  //if you change the delay value (from example change 50 to 10), the speed of the servo changes

  
  for (servoAngle = 0; servoAngle < 180; servoAngle++) //move the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);

    // ir code
    int value = analogRead (servoPin);
    int range = ((67870.0 / (value - 3.0)) - 40.0) / 10;

 //   Serial.println (range);
    delay(5);

      if (range > 10 and range < 30 )
    {/*
      if ( 0 < servoAngle and servoAngle < 90 ) {
        Serial.println("Forward Danger");
      }
      else
      {
        Serial.println("Right");
      }*/

    }
    // end of ir1 code
  }

  for (servoAngle = 180; servoAngle > 0; servoAngle--) //now move back the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);

    // ir code


    int value = analogRead (servoPin);
  int range = ((67870.0 / (value - 3.0)) - 40.0) / 10;

 
    if (range > 10 and range < 30 )
    {/*
      if ( 0 < servoAngle and servoAngle < 90 ) {
        Serial.println("Forward Danger");
      }
      else
      {
        Serial.println("Right");
      }
*/
    }


  }
  delay(5);
  //end of ir code
}


//end control the servo's speed
