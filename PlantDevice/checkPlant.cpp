#include "include/checkPlant.h"

void checkPlant(CollectData &sfu, DisplayActions &sfo, LedControl &sfa, BuzzerSong &sfe)
{
  if(sfu.getMoisture()<3000 || sfu.getLight()<3000 || sfu.getTemp()<90)
  {
    sfo.displayTextOnScreen("Plant Healthy!");
    sfa.ledPog();
    sfe.buzzerPog();
  }
  else
  {
    sfo.displayTextOnScreen("Water Plant :(");
    sfa.ledDog();
    sfe.buzzerDog();
  }
}