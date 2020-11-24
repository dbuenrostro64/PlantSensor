#include "include/DisplayActions.h"

// flash setup message on display at startup

void DisplayActions::displayInit(void)
{
  pinMode(BUTTON_PIN, INPUT);
  lcd.begin(LCD_COLS,LCD_ROWS);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Flora-Meter");
  lcd.setCursor(2,1);
  lcd.print("Version 1.0");
}

// displays data onto lcd display

void DisplayActions::displayOnScreen(float data)
{
  if ((millis() - lastUpdateLcd2) > updateLcd)
  {
    lastUpdateLcd2 = millis();
    lcd.setCursor(8,0);
    Serial.println(data);
    lcd.print(data);
  }
}

// displays titles onto lcd display

void DisplayActions::displayTitleOnScreen(String title)
{
  if ((millis() - lastUpdateLcd1) > updateLcd)
  {
    lastUpdateLcd1 = millis();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(title);
  }
}

// displays words onto lcd display

void DisplayActions::displayTextOnScreen(String words)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(words);
}

// debounce button
// changes display state when button is pressed

void DisplayActions::buttonPressCheck(CollectData& x)
{
  int reading = digitalRead(BUTTON_PIN);
  if(reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }
  // if button is held for holdButtonTime length
  if((millis() - lastDebounceTime) > holdButtonTime && buttonState == 1)  
  { 
    // collects data from all sensors
    x.takeMeasurement();
  }
  if((millis() - lastDebounceTime) > debounceDelay)
  {
    if(reading != buttonState)
    {
      buttonState = reading;
      
      if (buttonState == 1)
      {
        if(buttonPos == 4)
          buttonPos = 0;
        else
          buttonPos++;
      }
    }
  }
  lastButtonState = reading;
}

// changes display when button pressed

void DisplayActions::cycleDisplay(CollectData& x)
{
  // 4 button states that cycle 0-4
  if (buttonPos == 0)
  {
    //lcd.clear();
    displayTitleOnScreen("Soil:");
    displayOnScreen(x.soilMoisture);
  }
  else if (buttonPos == 1)
  {
    displayTitleOnScreen("Temp:");
    displayOnScreen(x.tempF);
    //lcd.clear();
  }
  else if (buttonPos == 2)
  {
    //lcd.clear();
    displayTitleOnScreen("Humid:");
    displayOnScreen(x.humidity);
  }
  else if (buttonPos == 3)
  {
    //lcd.clear();
    displayTitleOnScreen("Light:");
    displayOnScreen(x.light);
  }
  else if (buttonPos == 4)
  {
    //lcd.clear();
    displayTitleOnScreen("Bat:");
    displayOnScreen(x.batteryLife);
  }
}
