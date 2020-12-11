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

RTC_DATA_ATTR int bootCount = 0;
// --------------------------main code----------------------//

void setup() 
{
  Serial.begin(9600); 
  data1.dataInit();
  wifi1.wifiInit();
  display1.displayInit();
  led1.ledInit();
  buzz1.buzzerInit();
  bootCount++;
  delay(500);
}

void loop() 
{
  data1.takeMeasurement();
  if (data1.getBattery()>1000){
    wifi1.scanForWifi(data1.getTemp(), data1.getHumidity(), data1.getLight(), data1.getMoisture(), data1.getBattery()); 
    display1.buttonPressCheck(data1);
    display1.cycleDisplay(data1); 
  }
  else{
    led1.ledDog();
  }
}