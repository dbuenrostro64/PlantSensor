#include "include/checkPlant.h"


void checkPlant(CollectData &sfu, DisplayActions &sfo, LedControl &sfa, BuzzerSong &sfe)
{
  // if measured soil moisture value is low enough(high moisture)
  if(sfu.getMoisture()<3000)
  {
    // display on screen, blue led, and happy buzzer sound
    sfo.displayTextOnScreen("Plant Healthy!");
    sfa.ledPog();
    sfe.buzzerPog();
  }
  else
  {
    // display on screen, red led, and sad buzzer sound
    sfo.displayTextOnScreen("Water Plant :(");
    sfa.ledDog();
    sfe.buzzerDog();
  }
}