/*
    Author: Cody Stephenson

    This project's code is intended to drive the function of RGB strips.
    BRIGHTNESS_SWITCH and COLOR_SWITCH pins toggle through brightness and color settings.
*/
#include "ColorManager.h"

#define BRIGHTNESS_SWITCH 2
#define COLOR_SWITCH 8

#define RED_LED 9
#define GREEN_LED 5
#define BLUE_LED 6

ColorManager colorMgr = ColorManager();
const int waitingMs = 250; // .25 seconds
unsigned long previousMillis = 0;
bool shouldReadSwitches = false;
bool shouldPrintColors = false;

void setup() {
    // switches to control brightness and color
    // using pullup mode to take advantage of builtin pullup resistors
    pinMode(BRIGHTNESS_SWITCH, INPUT_PULLUP);
    pinMode(COLOR_SWITCH, INPUT_PULLUP);
    // RGB LED pins
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
    unsigned long currentMillis = millis();
    writeLEDs();
    checkSwitches(currentMillis);
}

void writeLEDs(){
    RGB currentColor = colorMgr.getRgb();
    analogWrite(RED_LED, currentColor.r);
    analogWrite(GREEN_LED, currentColor.g);
    analogWrite(BLUE_LED, currentColor.b);
    if (shouldPrintColors){
      Serial.print(currentColor.r);
      Serial.print("\t");
      Serial.print(currentColor.g);
      Serial.print("\t");
      Serial.print(currentColor.b);
      Serial.print("\n");
      shouldPrintColors = false;
    }
}

// read switch inputs based on frequency
void checkSwitches(unsigned long currentMillis) {
    if (currentMillis - previousMillis >= waitingMs){
        previousMillis = currentMillis;
        shouldReadSwitches = true;
    }
    if (shouldReadSwitches) {
        int bs = digitalRead(BRIGHTNESS_SWITCH);
        int cs = digitalRead(COLOR_SWITCH);
        if (bs == LOW){
          colorMgr.setNextBrightness();
          shouldPrintColors = true;
        }
        if (cs == LOW){
          colorMgr.setNextColor();
          shouldPrintColors = true;
        }
        shouldReadSwitches = false;
    }
}
