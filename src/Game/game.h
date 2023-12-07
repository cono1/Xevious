#pragma once

#include "Menu/menu.h"

namespace game
{
void initGame();
void updateGame(CurrentScreen& currentScreen, bool& restart, int& score);
void drawGame();
void deInitGame();
}