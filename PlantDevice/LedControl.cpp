#include "include/LedControl.h"

// flash lights at startup

void LedControl::ledInit(void)
{
  ledcSetup(LED_CHANNEL_RED, freq, resolution);
  ledcSetup(LED_CHANNEL_BLUE, freq, resolution);
  
  ledcAttachPin(LED_RED_PIN, LED_CHANNEL_RED);
  ledcAttachPin(LED_BLUE_PIN, LED_CHANNEL_BLUE);
  
  ledcWrite(LED_CHANNEL_RED, dutyCycleMid);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleOff);
  delay(375);
  ledcWrite(LED_CHANNEL_RED, dutyCycleOff);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleMid);
  delay(375);
  ledcWrite(LED_CHANNEL_RED, dutyCycleMid);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleOff);
  delay(375);
  ledcWrite(LED_CHANNEL_RED, dutyCycleOff);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleMid);
  delay(375);
  ledcWrite(LED_CHANNEL_RED, dutyCycleOff);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleOff);
}

// Blue light flashes

void LedControl::ledPog(void)
{
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleMid);
  delay(375);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleOff);
  delay(375);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleMid);
  delay(375);
  ledcWrite(LED_CHANNEL_BLUE, dutyCycleOff);
  
}

// Red light flashes

void LedControl::ledDog(void)
{
  ledcWrite(LED_CHANNEL_RED, dutyCycleMid);
  delay(375);
  ledcWrite(LED_CHANNEL_RED, dutyCycleOff);
  delay(375);
  ledcWrite(LED_CHANNEL_RED, dutyCycleMid);
  delay(375);
  ledcWrite(LED_CHANNEL_RED, dutyCycleOff);
}