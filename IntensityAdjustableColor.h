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
    IntensityAdjustableColor(const RGB* color_levels, unsigned char num_colors);
    IntensityAdjustableColor();
    void setNextBrightness();
    RGB getRgb() const;
private:
    unsigned char num_colors;
    const RGB* color_levels;
    RGB* current_color;
};

#endif
