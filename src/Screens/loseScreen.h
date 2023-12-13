#pragma once

#include "Menu/menu.h"

namespace game
{
void initLoseScreen();
void updateLoseScreen(CurrentScreen& currentScreen, bool& restart);
void printLoseScreen();
}