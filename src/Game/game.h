#pragma once

#include "gameManager.h"

namespace game
{
void initGame();
void updateGame(CurrentScreen& currentScreen, CurrentScreen& prevScreen, bool& restart);
void drawGame();
void deInitGame();
}