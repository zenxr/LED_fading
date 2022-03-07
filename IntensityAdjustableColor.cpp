#include "Arduino.h"
#include "IntensityAdjustableColor.h"

IntensityAdjustableColor::IntensityAdjustableColor(const RGB* colorLevels, unsigned char numColors) {
    this->colorLevels = colorLevels;
    this->numColors = numColors;
    this->currentColor = colorLevels;
}

RGB IntensityAdjustableColor::getRgb() const {
    return *currentColor;
}

void IntensityAdjustableColor::setNextBrightness(){
    RGB* end = (long)colorLevels + sizeof(RGB) * (numColors - 1);
    if (currentColor >= end){
        Serial.println("here");
        currentColor = colorLevels;
    } else {
        currentColor += 1;
    }
}
