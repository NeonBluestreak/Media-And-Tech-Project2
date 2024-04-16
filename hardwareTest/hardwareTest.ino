/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.
*
 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

Servo doorServo;

Servo moonServo;

Servo kaijuServo;

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const int buttonPin = 4;  // the number of the pushbutton pin
const int button2Pin = 2;
const int ledPin = 13;    // the number of the LED pin
int buttonState = 0;  // variable for reading the pushbutton status

int button2State = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  doorServo.attach(5);
  moonServo.attach(6);
  kaijuServo.attach(9);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(button2Pin, INPUT);
  myservo.write(0);
  doorServo.write(0);
  moonServo.write(0);
  kaijuServo.write(0);

}

void loop() {
  // read the state of the pushbutton value:
  Serial.println("_____");
  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(button2Pin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    myservo.write(180);
    doorServo.write(180);                    // waits 15 ms for the servo to reach the position
    moonServo.write(30);
    kaijuServo.write(180);
    Serial.println("button pressed!");
  } else if( button2State == HIGH){
    moonServo.write(55);
  
  }else{
    // turn LED off:
    myservo.write(0);
    doorServo.write(0);
    moonServo.write(80);
    kaijuServo.write(0);
  }

  if(button2State == HIGH) {
    Serial.println("button2 pressed!");

  }
 
}
