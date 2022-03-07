#ifndef IntensityAdjustableColor_h
#define IntensityAdjustableColor_h

#include "Arduino.h"

struct RGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class IntensityAdjustableColor {
public:
    IntensityAdjustableColor(const RGB* colorLevels, unsigned char numColors);
    IntensityAdjustableColor();
    void setNextBrightness();
    RGB getRgb() const;
private:
    unsigned char numColors;
    const RGB* colorLevels;
    RGB* currentColor;
};

#endif
