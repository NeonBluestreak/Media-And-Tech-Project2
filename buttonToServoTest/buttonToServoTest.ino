#include <Servo.h>

Servo firstServo; //interaction 1
int sensorVal;  //value register from piezo
const int sensorPin = A0;  //piezo
int ledPin = 6;  //fire in the village

int wallHit = 0;
//------------------------------------
Servo servo2;  // create servo object to control a servo
const int switch2 = 4;  // switch Aang to Zuko
int switch2State = 0;  

//------------------------------------
const int switch3 = 2;  // switch Aang to Koh
const int ledTrail = 13;    //LED trail to pin 13
int switch3State = 0;

//------------------------------------
Servo servo46;  // moon Yue servo
const int switch4 = 11;  // switch fireball to koi
int switch4State = 0; 

const int switch6 = 5; //switch Yue to Koi
int switch6State = 0;  

//------------------------------------
Servo servo5;  // Kaiju
const int switch5 = 7;  // switch Aang to oasis
int switch5State = 0;  



void setup() {
  firstServo.attach(9);  //first servo to pin 9
  pinMode(ledPin, OUTPUT); //fire village LED
  Serial.begin(9600);
//------------------------------------
 servo2.attach(3); //2nd servo to pin 3
  pinMode(switch2, INPUT);  //
 Serial.begin(9600);
//------------------------------------
  pinMode(ledTrail, OUTPUT);
  pinMode(switch3, INPUT);
  //------------------------------------
 servo46.attach(8); //4/6 servo to pin 8
  pinMode(switch4, INPUT);
  pinMode(switch6, INPUT);
 Serial.begin(9600);
  //------------------------------------
 servo5.attach(10); //5th servo to pin 10
  pinMode(switch5, INPUT);
 Serial.begin(9600);
}

void loop() {
//------------------------------------interaction 1
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);

  if (sensorVal >= 23) {
    wallHit++;
  }

  if (wallHit > 1) {
    digitalWrite(ledPin, HIGH);
    firstServo.write(180);
  } else {
    firstServo.write(0);
  }
//------------------------------------interaction 2
  switch2State = digitalRead(switch2);

  if (switch2State == HIGH) {
    servo2.write(180);                    // waits 15 ms for the servo to reach the position
  } else {
    servo2.write(0);
  }
//------------------------------------interaction 3
   switch3State = digitalRead(switch3);
  if (switch3State == HIGH) {
    digitalWrite(ledTrail, HIGH);  //LED on
  } else {
    digitalWrite(ledTrail, LOW);  //LED off
  }
}
//------------------------------------interaction 4/6
  switch4State = digitalRead(switch4);
  switch6State = digitalRead(switch6);

  if (switch4State == HIGH) {
    servo46.write(180);                    // waits 15 ms for the servo to reach the position
  } else {
    servo46.write(0);
  }

  if (switch6State == HIGH) {
    servo46.write(180);                    // waits 15 ms for the servo to reach the position
  } else {
    servo46.write(0);
  }
//------------------------------------interaction 5
  switch5State = digitalRead(switch5);

  if (switch5State == HIGH) {
    servo5.write(180);                    // waits 15 ms for the servo to reach the position
  } else {
    servo5.write(0);
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
---------------------Interaction #4-----------------------
const int switch4 = 2;  // the number of the pushbutton pin
const int ledTrail = 13;    // the number of the LED pin

int switch4State = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledTrail, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(switch4, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  switch4State = digitalRead(switch4);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (switch4State == HIGH) {
    // turn LED on:
    digitalWrite(ledTrail, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledTrail, LOW);
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
