#pragma once

namespace game
{
enum CurrentScreen { PLAY, RULES, CREDITS, EXIT, MENU, PAUSE, LOSE };
void gameLoop();
void checkGoBack();
}