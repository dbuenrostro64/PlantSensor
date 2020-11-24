#ifndef BUZZERSONG_H
#define BUZZERSONG_H

#include <Arduino.h>

//-----Piano Note Frequencies-------
#define F3_NOTE 175
#define F33_NOTE 185
#define G3_NOTE 196
#define C4_NOTE 262
#define D4_NOTE 294
#define F4_NOTE 349
#define G4_NOTE 392
#define A4_NOTE 440
#define C5_NOTE 525
#define E5_NOTE 659
#define A5_NOTE 880
#define C6_NOTE 1047




class BuzzerSong{
    private:
        const byte BUZZER_PIN = 26;
        const int BUZZER_CHANNEL_1 = 3;
        const int resolution = 12;
        int freq = 5000;
        int buzzDutyCycle = 2000;

        
    public:
        // sets channels and pins
        BuzzerSong();
        // buzzer tune when at startup
        void buzzerInit(void);
        // Happy buzzer sound
        void buzzerPog(void);
        // Sad buzzer sound
        void buzzerDog(void);
};

#endif