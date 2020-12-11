#include <Arduino.h>
#include "include/Buzzersong.h"

BuzzerSong::BuzzerSong()
        {
            ledcSetup(BUZZER_CHANNEL_1, freq, resolution);
            ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL_1);
        }

// buzzer tune when at startup

void BuzzerSong::buzzerInit()
{
  ledcWriteTone(BUZZER_CHANNEL_1, G3_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(350);
  ledcWriteTone(BUZZER_CHANNEL_1, C4_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(300);
  ledcWriteTone(BUZZER_CHANNEL_1, F3_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(150);
  ledcWrite(BUZZER_CHANNEL_1, 0);
}

// widepeepohappy

void BuzzerSong::buzzerPog(void)
{
  ledcWriteTone(BUZZER_CHANNEL_1, A4_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(100);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(100);
  ledcWriteTone(BUZZER_CHANNEL_1, C5_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(100);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(100);
  ledcWriteTone(BUZZER_CHANNEL_1, E5_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(100);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(100);
  ledcWriteTone(BUZZER_CHANNEL_1, A5_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(100);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(100);
  ledcWriteTone(BUZZER_CHANNEL_1, C6_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(100);
  ledcWrite(BUZZER_CHANNEL_1, 0);
}

// not widepeepohappy

void BuzzerSong::buzzerDog(void)
{
  ledcWriteTone(BUZZER_CHANNEL_1, D4_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(75);
  ledcWrite(BUZZER_CHANNEL_1, 0);
  delay(75);
  ledcWriteTone(BUZZER_CHANNEL_1, G3_NOTE);
  ledcWrite(BUZZER_CHANNEL_1, buzzDutyCycle); 
  delay(75);
  ledcWrite(BUZZER_CHANNEL_1, 0);
}