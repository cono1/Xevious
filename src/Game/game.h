#pragma once

#include "gameManager.h"

namespace game
{
void initGame();
void updateGame(CurrentScreen& currentScreen, bool& restart);
void drawGame();
void deInitGame();
}