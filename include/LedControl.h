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
        void ledInit(void);
        void ledPog(void);
        void ledDog(void);
};

#endif