#include "ColorManager.h"
#include "Arduino.h"

const RGB RED[5] = {
    {50, 50, 50},
    {100, 100, 100},
    {150, 150, 150},
    {200, 200, 200},
    {255, 255, 255}
};
IntensityAdjustableColor RED_ADJUSTABLE = IntensityAdjustableColor(RED, sizeof(RED) / sizeof(RGB));

const RGB WHITE[5] = {
    {51, 10, 51},
    {101, 101, 101},
    {151, 151, 151},
    {201, 201, 201},
    {251, 251, 251}
};
IntensityAdjustableColor WHITE_ADJUSTABLE = IntensityAdjustableColor(WHITE, sizeof(WHITE) / sizeof(RGB));

const RGB YELLOW[5] = {
    {52, 52, 52},
    {102, 102, 102},
    {152, 152, 152},
    {202, 202, 202},
    {252, 252, 252}
};
IntensityAdjustableColor YELLOW_ADJUSTABLE = IntensityAdjustableColor(YELLOW, sizeof(YELLOW) / sizeof(RGB));

ColorManager::ColorManager()
{
    len_colors = 0;
    addColor(RED_ADJUSTABLE);
    addColor(WHITE_ADJUSTABLE);
    addColor(YELLOW_ADJUSTABLE);
    current_color = *colors;
}

RGB ColorManager::getRgb() const{
    return current_color->getRgb();
}

void ColorManager::setNextColor(){
    const IntensityAdjustableColor* end = colors[0] + sizeof(IntensityAdjustableColor) * len_colors;
    if (current_color == end){
        current_color = *colors;
    } else {
        current_color = static_cast<IntensityAdjustableColor *>(current_color + sizeof(IntensityAdjustableColor));
    }
}

void ColorManager::setNextBrightness(){
    current_color->setNextBrightness();
}

void ColorManager::addColor(IntensityAdjustableColor& color){
    len_colors += 1;
    colors[len_colors - 1] = &color;
}
