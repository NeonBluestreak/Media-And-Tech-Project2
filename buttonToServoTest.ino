/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const int buttonPin = 8;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    myservo.write(180);                    // waits 15 ms for the servo to reach the position
  } else {
    // turn LED off:
    myservo.write(0);
  }

 
}