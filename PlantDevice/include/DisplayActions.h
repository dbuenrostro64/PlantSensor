#ifndef DISPLAYACTIONS_H
#define DISPLAYACTIONS_H

#include <LiquidCrystal.h>
#include "include/CollectData.h"

class DisplayActions{
    
    private:
        const byte LCD_COLS = 16;
        const byte LCD_ROWS = 2;
        const byte LCD_D4_PIN = 27;
        const byte LCD_D5_PIN = 13;
        const byte LCD_D6_PIN = 14;
        const byte LCD_D7_PIN = 15;
        const byte LCD_E_PIN = 18;
        const byte LCD_RS_PIN = 19;
        const int BUTTON_PIN = 25;
        int buttonState;
        int lastButtonState = 0;
        int buttonPos = 0; // 0-4
        unsigned long lastDebounceTime = 0;
        unsigned long debounceDelay = 50;
        unsigned long timeHeld = 0;
        int holdButtonTime = 3000;
        unsigned long lastUpdateLcd1 = 0;
        unsigned long lastUpdateLcd2 = 0;
        int updateLcd = 250;
        void displayOnScreen(float data);
        void displayTitleOnScreen(String title);
    public:
        DisplayActions() : lcd(LCD_RS_PIN,LCD_E_PIN,LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN) {}
        LiquidCrystal lcd;
        void displayInit(void);
        void buttonPressCheck(CollectData& x);
        void cycleDisplay(CollectData& x);
        void displayTextOnScreen(String words);
};

#endif