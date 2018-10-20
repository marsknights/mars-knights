

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
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 13, d4 = 30, d5 = 28, d6 = 26, d7 = 24;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
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
   lcd.begin(16, 2);
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

    lcd.print("Normal State.");

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
  
   lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  servo.write(45);
  delay(1000);
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
if (( distance1 < 30 && distance1 > 10) or (( distance2 < 30 && distance2 > 10)) ) {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    noTone(buzzer);     // Stop sound...
    right();
    delay(1500);
    forward();
    delay(2000);
    left();
    delay(1500);
 lcd.print("Danger!!!");
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  } else {pause();}
  

 
 
  servo.write(135);
  delay(1000);
   digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;
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
if (( distance1 < 30 && distance1 > 10) or (( distance2 < 30 && distance2 > 10)) ) {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    noTone(buzzer);     // Stop sound...
   lcd.print("Danger!!!");
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
    forward();
    delay(2000);
  


  } else {pause();}
  


  servo.write(45);
     delay(1000);
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
if (( distance1 < 30 && distance1 > 10) or (( distance2 < 30 && distance2 > 10)) ) {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    noTone(buzzer);    
    lcd.print("Danger!!!");
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);// Stop sound...
    right();
    delay(1500);
    forward();
    delay(2000);
    left();
    delay(1500);


  } else {pause();}
  

}
