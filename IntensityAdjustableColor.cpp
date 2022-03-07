#include "Arduino.h"
#include "IntensityAdjustableColor.h"

IntensityAdjustableColor::IntensityAdjustableColor(const RGB* color_levels, unsigned char num_colors) {
    this->color_levels = color_levels;
    this->num_colors = num_colors;
    this->current_color = color_levels;
}

RGB IntensityAdjustableColor::getRgb() const {
    return *current_color;
}

void IntensityAdjustableColor::setNextBrightness(){
    RGB* end = (long)color_levels + sizeof(RGB) * (num_colors - 1);
    if (current_color >= end){
        Serial.println("here");
        current_color = color_levels;
    } else {
        current_color += 1;
    }
}
