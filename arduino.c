
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

float tmp_pin = A0;  // analog pin used to connect the temp sensor
int sensorip;  
double temp;
int turn;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  sensorip = analogRead(tmp_pin); 
  Serial.print(sensorip);
  Serial.print(" ");
 temp=(double)sensorip/1024;
  Serial.print(temp);
  Serial.print(" ");
  temp=temp*5;
  Serial.print(temp);
  Serial.print(" ");
  temp=temp-0.5;
  Serial.print(temp);
  Serial.print(" ");
  temp=temp*100;
  Serial.print(temp);
  Serial.print(" ");// reads the value of the temp sensor (value between 0 and 1023)
   turn= map(temp, -50, 125, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(turn);
  Serial.print(turn);
  Serial.println();// sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
