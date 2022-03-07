#ifndef ColorManager_h
#define ColorManager_h

#include "Arduino.h"
#include "string.h"
#include "IntensityAdjustableColor.h"

#define MAX_COLORS 10

class ColorManager {
public:
    ColorManager();
    RGB getRgb() const;

    void setNextColor();
    void setNextBrightness();

private:
    void addColor(IntensityAdjustableColor& color);

    IntensityAdjustableColor* colors[MAX_COLORS];
    unsigned char lenColors;
    IntensityAdjustableColor* currentColor;
    unsigned char currentColrIdx;
};

#endif
