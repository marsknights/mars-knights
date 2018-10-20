

/*
  Into Robotics
*/
const int buzzer = 7;
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;
int ena = 11;
int enb = 10;
char junk;
String inputString = "";
#include <Servo.h>  //add '<' && '>' before && after servo.h

int servoPin = 9;
Servo servo;

const int trigPin1 = A1;
const int echoPin1 = A2;
//trig2 A3
//echo2 A4
// defines variables
long duration1;
int distance1;
const int trigPin2 = A3;
const int echoPin2 = A4;
// defines variables
long duration2;
int distance2;
int servoAngle = 0;   // servo position in degrees

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(buzzer, OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
}

int ultra1() {
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  return distance1;
}

int ultra2() {
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  return distance2;
}
void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
}
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
}

void back() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
}
void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
}

void pause() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}


void loop()
{
  if (Serial.available()) {
    while (Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)
    {
      junk = Serial.read() ;  // clear the serial buffer
    }
    if (inputString == "f") {       //in case of 'a' turn the LED on
      forward();
    } else if (inputString == "b") { //incase of 'b' turn the LED off
      back();
    }
    else if (inputString == "r") { //incase of 'b' turn the LED off
      right();
    }
    else if (inputString == "l") { //incase of 'b' turn the LED off
      left();
    }
    else if (inputString == "s") { //incase of 'b' turn the LED off
      pause();
    }
    inputString = "";
  }
  /*********** forward then back **********/
  for (servoAngle = 0; servoAngle < 90; servoAngle++) //move the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);
    byte distance11 = ultra1();
    if (distance11 > 20 && distance11 < 45 ) {
      delay(50);

      byte distance111 = ultra1();
      if (distance111 > 20 && distance111 < 45 ) {
        byte diff1 = distance111 - distance11;
        if (diff1 > 3 && diff1 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...
          right();
          delay(1500);
          forward();
          delay(1000);
          left();
          delay(1500);
          // action ends
        }
      }
    }
    byte distance22 = ultra2();
    if (distance22 > 20 && distance22 < 45 ) {

      byte distance222 = ultra2();
      if (distance222 > 20 && distance222 < 45 ) {
        byte diff2 = distance222 - distance22;
        if (diff2 > 3 && diff2 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...
          right();
          delay(1500);
          forward();
          delay(1000);
          left();
          delay(1500);
          // action ends
        }
      }
    }
  }

  /***********right and left **********/
  for (servoAngle = 90; servoAngle < 180; servoAngle++) //move the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);
    byte distance11 = ultra1();
    if (distance11 > 20 && distance11 < 45 ) {
      delay(50);

      byte distance111 = ultra1();
      if (distance111 > 20 && distance111 < 45 ) {
        byte diff1 = distance111 - distance11;
        if (diff1 > 3 && diff1 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...

          forward();
          delay(1000);

          // action ends
        }
      }
    }
    byte distance22 = ultra2();
    if (distance22 > 20 && distance22 < 45 ) {
      byte distance222 = ultra2();
      if (distance222 > 20 && distance222 < 45 ) {
        byte diff2 = distance222 - distance22;
        if (diff2 > 3 && diff2 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...

          forward();
          delay(1000);

          // action ends
        }
      }
    }
  }

  /******** right and left incoming ***********/
  for (servoAngle = 180; servoAngle > 90; servoAngle--) //now move back the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);
    byte distance11 = ultra1();
    if (distance11 > 20 && distance11 < 45 ) {
      delay(50);
      byte distance111 = ultra1();
      if (distance111 > 20 && distance111 < 45 ) {
        byte diff1 = distance111 - distance11;
        if (diff1 > 3 && diff1 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...

          forward();
          delay(1000);

          // action ends
        }
      }
    }
    byte distance22 = ultra2();
    if (distance22 > 20 && distance22 < 45 ) {
      byte distance222 = ultra2();
      if (distance222 > 20 && distance222 < 45 ) {
        byte diff2 = distance222 - distance22;
        if (diff2 > 3 && diff2 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...

          forward();
          delay(1000);

          // action ends
        }
      }
    }
  }

  /********** forward then back incoming **********/
  for (servoAngle = 90; servoAngle > 0; servoAngle--) //now move back the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);
    byte distance11 = ultra1();
    if (distance11 > 20 && distance11 < 45 ) {
      delay(50);
      byte distance111 = ultra1();
      if (distance111 > 20 && distance111 < 45 ) {
        byte diff1 = distance111 - distance11;
        if (diff1 > 3 && diff1 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...
          right();
          delay(1500);
          forward();
          delay(1000);
          left();
          delay(1500);
          // actionends
        }
      }
    }
    byte distance22 = ultra2();
    if (distance22 > 20 && distance22 < 45 ) {
      byte distance222 = ultra2();
      if (distance222 > 20 && distance222 < 45 ) {
        byte diff2 = distance222 - distance22;
        if (diff2 > 3 && diff2 < 20) {
          // action starts
          tone(buzzer, 2000); // Send 1KHz sound signal...
          noTone(buzzer);     // Stop sound...
          right();
          delay(1500);
          forward();
          delay(1000);
          left();
          delay(1500);
          // action ends
        }
      }
    }
  }

}
