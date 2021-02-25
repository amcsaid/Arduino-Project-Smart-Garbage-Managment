#include <Servo.h>
#include <SoftwareSerial.h>
#define trigPin 6
#define echoPin 7
Servo servo;
SoftwareSerial myser(2,3);// RX,TX
int sound = 250;
void setup() {
  myser.begin(9600);
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(10);
}
void loop() {
long duration, distance;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance < 10) {
Serial.println("the distance is less than 10");
servo.write(90);
delay(1500);
}
else {
servo.write(0);
}
if (distance > 60 || distance <= 0){
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(500);
if(Serial.available()>0){
  myser.write(Serial.read());}
}
