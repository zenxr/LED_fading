# LED Control software

This project's code is intended to drive the function of RGB strips via buttons. I didn't like the idea of having a remote control tied to my vehicle, and physical switches are more robust. Additionally, I only want a select few colors of light - namely amber, white, and red. In this case, driving 12V 5050-SMD LEDs from a 5v Pro Micro clone using MOSFETS.

# Design

- `LED_Fading` - Main Arduino Sketch, contains `setup()` and `loop()`
  - Expandable via adding new routines as needed
  - Routines are set up so that button reading is disabled for an interval immediately after a press is detected.
- `Color Manager` - Contains a list of `IntensityAdjustableColors` and is able to iterate through them.
- `IntensityAdjustableColor` - Represents a single color, with adjustable brightness levels.
  - As some colors on most RGB strips don't behave consistently through input levels, each RGB value for a given brightness is configurable.
