#pragma once

#include <string>

namespace game
{
enum CurrentScreen { PLAY, RULES, CREDITS, EXIT, MENU, PAUSE, LOSE };

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
void updateMenu(CurrentScreen& currentScreen, bool& playAgain);
void printMenu(std::string title, std::string firstOption, int titleSize, int optionsSize);
bool checkCursorMenuCollision(MenuRect& menuRec, float initWidth, float maxWidth);
void printBackButton(bool pause, int fontSize);
bool isMouseHoverPause();
}