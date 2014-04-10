/* Encoder Library - TwoKnobs Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
// Encoder knobLeft(18, 19);
Encoder knobRight(0, 1);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("MIDI Encoder Test:");
}

// long positionLeft  = -999;
long positionRight = -999;

void loop() {
  long newLeft, newRight;
  // newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newRight != positionRight) {
    
    if(newRight > positionRight){
    //Send +1 signal
    Serial.print("Direction: +1 ");
    }
    else{
    //Send -1 signal
    Serial.print("Direction: -1 ");
    
    }
    
    // Serial.print("Left = ");
    // Serial.print(newLeft);
    //Serial.print(", Value = ");
    //Serial.print(newRight);
    Serial.println();
    // positionLeft = newLeft;
    positionRight = newRight;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset knob to zero");
    // knobLeft.write(0);
    knobRight.write(0);
  }
}
