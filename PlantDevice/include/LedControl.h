#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>



class LedControl{
    private:
        const int LED_RED_PIN = 32;
        const int LED_BLUE_PIN = 33;
        const int LED_CHANNEL_RED = 0;
        const int LED_CHANNEL_BLUE = 1;
        int dutyCycleMid = 2048;
        int dutyCycleOff = 4095;
        int freq = 5000;
        int resolution = 12;
    public:
        // flash lights at startup
        void ledInit(void);
        // Blue light flashes
        void ledPog(void);
        // Red light flashes
        void ledDog(void);
};

#endif