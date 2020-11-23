//========PLANT CODE========//

// include headers
#include <Arduino.h>
#include "include/CollectData.h"
#include "include/DataToPi.h"
#include "include/BuzzerSong.h"
#include "include/DisplayActions.h"
#include "include/LedControl.h"
#include "include/checkPlant.h"

//-----------------definitions and declarations-------------//

CollectData data1;
DisplayActions display1;
LedControl led1;
BuzzerSong buzz1;
DataToPi wifi1;

// --------------------------main code----------------------//

void setup() 
{
  Serial.begin(9600); 
  data1.dataInit();
  // wifi1.wifiInit();
  display1.displayInit();
  led1.ledInit();
  buzz1.buzzerInit();
  delay(500);
}

void loop() 
{
  data1.takeMeasurement();
  display1.buttonPressCheck(data1);
  display1.cycleDisplay(data1);
  //scanForWifi(); 
}