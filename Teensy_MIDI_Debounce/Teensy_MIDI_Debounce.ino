//MIDI Button Debounce for Teensy 2.0++

//libraries
#include <Wire.h>

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 26;    // the number of the pushbutton pin
const int led = 6; //ref LED pin

// initialize button state variables
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup(){
  //turn on pin for button
   pinMode(buttonPin,INPUT_PULLUP);
   // initialize the digital pin as an output.
   pinMode(led, OUTPUT);
   
   //Power on Blink Test
   digitalWrite(led, HIGH);
   delay(1000);
   digitalWrite(led, LOW);
   
   //Serial monitoring
   Serial.begin(9600);
}

void loop() {
  
        digitalWrite(led, LOW);
  
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the MIDI note if the new button state is HIGH
      if (buttonState == LOW) {
        
        Serial.println("PRESS");
        
        // usbMIDI.sendNoteOn(10, 100, 10);
        
        //fire the LED to show the switch is working
        digitalWrite(led, HIGH);
        delay(1000);
        
      }
    }
  }
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}
