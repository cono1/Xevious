#pragma once

#include "gameManager.h"

namespace game
{
void initLoseScreen();
void updateLoseScreen(CurrentScreen& currentScreen, bool& restart);
void printLoseScreen();
}