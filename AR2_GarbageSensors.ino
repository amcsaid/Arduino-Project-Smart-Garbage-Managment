#include <Servo.h>
#include <SoftwareSerial.h>

// US 1: 
#define trigPint 4  // ultrasonic 2 bt
#define echoPint 5  // ultrasonic 2 bt

// US 2: 
#define trigPin 6  // ultrasonic triger motor
#define echoPin 7  // ultrasonic echo  motor

// BT Master
SoftwareSerial myser(2,3);// TX,RX

// Moteur
Servo servo; 

void setup() {
  // ultrasonic 1 avec motor
  pinMode(trigPin, OUTPUT); // ultrasonic triger motor
  pinMode(echoPin, INPUT); // ultrasonic triger motor
  
  // ultrasonic 2 avec BT
  pinMode(trigPint, OUTPUT);
  pinMode(echoPint, INPUT);
  myser.begin(9600);
  
  //  motor
  servo.attach(10); 
}


void loop() {
  //
  //
  // UltraSonic 2 avec BT
  //
  // 
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  if (duration < 680) { // eq to 10cm
    servo.write(90);
    delay(1500);
  } 
  else {
    servo.write(0);
  }

  //
  //
  // UltraSonic 1 avec BT
  //
  // 
  long durationt;
  int toprint;

  digitalWrite(trigPint, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPint, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPint, LOW);

  durationt = pulseIn(echoPint, HIGH);
  Serial.println(durationt);
  

  if (durationt > 1800) { // eq a vide
    
  } else if (durationt > 1600)  {
    toprint = 1;
  } else if (durationt > 1440)  {
    toprint = 2;
  } else if (durationt > 1280)  {
    toprint = 3;
  } else if (durationt > 1120)  {
    toprint = 4;
  } else if (durationt > 960)   {
    toprint = 5;
  } else if (durationt > 800)   {
    toprint = 6;
  } else if (durationt > 640)   {
    toprint = 7;
  } else if (durationt > 480)   {
    toprint = 8;
  } else {
    toprint = 9;
  } 
  
  myser.write(toprint+48);
  delay(500);
}
