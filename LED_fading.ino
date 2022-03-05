/*
    Author: Cody Stephenson
*/
#include "ColorManager.h"

#define BRIGHTNESS_SWITCH 2
#define COLOR_SWITCH 8

#define RED_LED 9
#define GREEN_LED 5
#define BLUE_LED 6

ColorManager colorMgr = ColorManager();
const int waitingMs = 200; // .2 seconds
unsigned long previousMillis = 0;

void setup() {
    // switches to control brightness and color
    pinMode(BRIGHTNESS_SWITCH, INPUT);
    pinMode(COLOR_SWITCH, INPUT);
    // RGB LED pins
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
    unsigned long currentMillis = millis();

    RGB currentColor = colorMgr.getRgb();
    analogWrite(RED_LED, currentColor.r);
    analogWrite(GREEN_LED, currentColor.g);
    analogWrite(BLUE_LED, currentColor.b);

    if (currentMillis - previousMillis >= waitingMs){
        previousMillis = currentMillis;
        int bs = digitalRead(BRIGHTNESS_SWITCH);
        int cs = digitalRead(COLOR_SWITCH);
        if (bs == HIGH)
        {
            Serial.println("brightness switch");
            colorMgr.setNextBrightness();
        }
        if (cs == HIGH){
            Serial.println("color switch");
            colorMgr.setNextColor();
        }
    }
}
