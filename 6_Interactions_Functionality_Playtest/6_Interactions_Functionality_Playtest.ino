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

bool interaction2 = false;
//------------------------------------
const int switch3 = 2;  // switch Aang to Koh
const int ledTrail = 13;    //LED trail to pin 13
int switch3State = 0;

bool interaction3 = false;
//------------------------------------
Servo servo46;  // moon Yue servo
const int switch4 = 11;  // switch fireball to koi
int switch4State = 0; 

const int switch6 = 5; //switch Yue to Koi
int switch6State = 0;  

bool interaction4 = false;
bool interaction6 = false;
//------------------------------------
Servo servo5;  // Kaiju
const int switch5 = 7;  // switch Aang to oasis
int switch5State = 0;  
bool interaction5 = false;


void setup() {
  firstServo.attach(9);  //first servo to pin 9
  pinMode(ledPin, OUTPUT); //fire village LED
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
//------------------------------------
 servo2.attach(3); //2nd servo to pin 3
  pinMode(switch2, INPUT);  //
 Serial.begin(9600);
 servo2.write(0);
//------------------------------------
  pinMode(ledTrail, OUTPUT);
  pinMode(switch3, INPUT);
  digitalWrite(ledTrail, LOW);
  //------------------------------------
 servo46.attach(8); //4/6 servo to pin 8
  pinMode(switch4, INPUT);
  pinMode(switch6, INPUT);
  servo46.write(80);
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
    servo2.write(55);                    // waits 15 ms for the servo to reach the position
  } else {
    //servo2.write(0);
  }
//------------------------------------interaction 3
   switch3State = digitalRead(switch3);
  if (switch3State == HIGH) {
    digitalWrite(ledTrail, HIGH);  //LED on
  } else {
    //digitalWrite(ledTrail, LOW);  //LED off
  }
//------------------------------------interaction 4/6
  switch4State = digitalRead(switch4);
  switch6State = digitalRead(switch6);

  if (switch4State == HIGH) {
    servo46.write(60);                    // waits 15 ms for the servo to reach the position
  } else {
    //servo46.write(80);
  }

  if (switch6State == HIGH) {
    servo46.write(20);                    // waits 15 ms for the servo to reach the position
    Serial.println("servo switch 6 triggered");
  } else {
    //servo46.write(80);
  }
//------------------------------------interaction 5
  switch5State = digitalRead(switch5);

  if (switch5State == HIGH) {
    servo5.write(180);                    // waits 15 ms for the servo to reach the position
  } else {
    servo5.write(0);
  }
}