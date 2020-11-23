#ifndef CHECKPLANT_H
#define CHECKPLANT_H

#include "include/CollectData.h"
#include "include/DisplayActions.h"
#include "include/LedControl.h"
#include "include/BuzzerSong.h"

// fix circular include problem
class DisplayActions;

void checkPlant(CollectData &sfu, DisplayActions &sfo, LedControl &sfa, BuzzerSong &sfe);

#endif
