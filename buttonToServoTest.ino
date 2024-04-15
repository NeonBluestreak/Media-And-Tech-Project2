#include <Servo.h>

Servo firstServo; //interaction 1
int sensorVal;  //value register from piezo
const int sensorPin = A0;
int ledPin = 6;  //fire in the village

int wallHit = 0;


Servo servo2;  // create servo object to control a servo
const int switch2 = 4;  // switch Aang to Zuko
int switch2State = 0;  // variable for reading the pushbutton status

void setup() {
  firstServo.attach(9);  //first servo to pin 9
  pinMode(ledPin, OUTPUT); //fire village LED
  Serial.begin(9600);

 servo2.attach(3); //2nd servo to pin 3
  pinMode(switch2, INPUT);
 Serial.begin(9600);

}

void loop() {
 //interaction 1
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);

  if (sensorVal >= 30) {
    wallHit++;
  }

  if (wallHit > 1) {
    digitalWrite(ledPin, HIGH);
    firstServo.write(180);
  } else {
    firstServo.write(0);
  }
 //interaction 2
 
  // read the state of the pushbutton value:
  switch2State = digitalRead(switch2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (switch2State == HIGH) {
    servo2.write(180);                    // waits 15 ms for the servo to reach the position
  } else {
    servo2.write(0);
  }

 
}

/*
---------------------Interaction #1-----------------------
#include <Servo.h>

Servo firstServo;
int sensorVal;  //value register from piezo
const int sensorPin = A0;
int ledPin = 6;  //fire in the village

int wallHit = 0;


void setup() {
  firstServo.attach(9);  //servo to pin 9
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);

  if (sensorVal >= 30) {
    wallHit++;
  }

  if (wallHit > 1) {
    digitalWrite(ledPin, HIGH);
    firstServo.write(180);
  } else {
    firstServo.write(0);
  }
}

----------------------draft---------------------------
if (piezoVal > some number) {
 turn LED on;
 activate servo, oasis entrence opens;
}

if (Aang is next to Zuko, switch on) {
 activate servo, L2 cave opens;
 }

if (Aang is next to Koh, switch on) {
 activate servo, Heibei revealed;
}

if (Aang is on Heibei, switch on) {
 turn LED on;
}

if (fireball kills koi fish, switch on) {
 activate servo, moon disappears;
}

if (Aang is in oasis, switch on) {
 activate servo, Kaiju appears;
}

if (Princess Yue is in oasis, switch on) {
 activate servo, spirit & moon appear;
}
*/
