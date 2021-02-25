#include <SoftwareSerial.h>
SoftwareSerial BTSerial(6, 5); //  TX,RX

char c = ' ';
boolean NL = true;
int triggerPin = 2; //triggering on pin 7
int echoPin = 3;    //echo on pin 8

int info = 0;//variable for the information comming from the bluetooth module
int state = 0;//simple variable for displaying the state

void setup() { //we will be combinig both setups from the codes
  


  //Set to HC-05 default baud rate, found using AT+UART.  It is usually 38400.
  BTSerial.begin(9600);
  Serial.println("BTserial started at 38400");
  Serial.println("");
  Serial.begin(9600);  //we'll start serial comunication, so we can see the distance on the serial monitor
  
  pinMode(triggerPin, OUTPUT); //defining pins
  pinMode(echoPin, INPUT);
 
  
}

void loop(){ //here we combine both codes to work in the loop
   //Bluetooth();
  sensor();
}





void sensor() { //loop from the sensor code is renamed to the "sensor" void
  
  int duration, distance;    //Adding duration and distance
  
  digitalWrite(triggerPin, HIGH); //triggering the wave(like blinking an LED)
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
  
  Serial.print(distance);    //printing the numbers
  Serial.print("cm");       //and the unit
  Serial.println(" ");      //just printing to a new line
  
  //adding for mesuring distance where the led will turn off, even if we tell it to turn off when we chose so in the app
  
  if(distance <= 10){  
    
     Serial.write(distance);
     
   
    // Echo the user input to the main window. The ">" character indicates the user entered text.
    if (NL) {
      Serial.print(">");
      NL = false;
    }
    Serial.write(distance);
    if (distance == 10) {
      NL = true;
    }
  
     }
  
   if(distance >= 30){ 
    Serial.println(distance);
     
  }
}
