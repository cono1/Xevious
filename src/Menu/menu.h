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
void updateMenu(CurrentScreen& currentScreen);
void printMenu(std::string title, std::string firstOption, int titleSize, int optionsSize);
bool checkCursorMenuCollision(MenuRect& menuRec, float initWidth, float maxWidth);
void printBackButton(bool pause, int fontSize);
bool isMouseHoverPause();
}