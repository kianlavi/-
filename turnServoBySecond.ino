#include <Time.h>
#include <TimeLib.h>
#include <Servo.h>

Servo myservo;

// constants won't change. Used here to set a pin number :
const int ledPin =  13;      // the number of the LED pin

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)


void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  setTime(15, 18, 0, 18, 11, 2016);
  myservo.attach(9);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

//    Serial.print(now());
     Serial.print(hour());
     Serial.print(":");
     Serial.print(minute());
     Serial.print(":");
     Serial.println(second());
//     Serial.print(day());

//    setRotation(second());
//    Serial.println(myservo.read());

    if (second() == 5 || second() == 15 || second() == 25 || second() == 35) {
      myservo.write(180);
    } 
    else if (second() == 9 || second() == 19 || second() == 28 || second() == 37) {
      myservo.write(90);
    }





     

  
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

//int setRotation(int second) {
//  myservo.write(second * 5); 
//  Serial.print("Wrote: ");
//  Serial.println(second);
//}

