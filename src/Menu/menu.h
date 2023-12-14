#pragma once

#include <string>

#include "gameManager.h"

namespace game
{
struct MenuRect
{
	int x;
	int y;
	float width;
	float height;
	float initWidth;
	float maxWidth;
};

void initMenu(const int screenWidth);
void updateMenu(CurrentScreen& currentScreen, CurrentScreen& prevScreen, bool& closeGame);
void printMenu(std::string title, std::string firstOption);
bool checkCursorMenuCollision(MenuRect& menuRec, float initWidth, float maxWidth);
bool isMouseHoverPause();
}