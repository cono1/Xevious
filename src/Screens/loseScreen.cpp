#include "loseScreen.h"

#include <string>

#include "raylib.h"

namespace game
{
static MenuRect playAgain;
static MenuRect mainMenu;

static int optionsSize = 40;

void initOptions();
void updateOptions(CurrentScreen& currentScreen, bool& restart);
void printOptions();

void printLoseScreen(CurrentScreen& currentScreen, bool& restart)
{
	std::string loseText = "You lost";
	int loseTextSize = 80;
	int loseTextX = (GetScreenWidth() - MeasureText(loseText.c_str(), loseTextSize)) / 2;
	int loseTextY = 200;

	DrawText(TextFormat(loseText.c_str()), loseTextX, loseTextY, loseTextSize, WHITE);

	initOptions();
	updateOptions(currentScreen, restart);
	printOptions();
}

void initOptions()
{
	optionsSize = 40;

	playAgain.width = 350;
	playAgain.height = 80;
	playAgain.x = GetScreenWidth() / 2;
	playAgain.y = 390;
	playAgain.initWidth = playAgain.width;
	playAgain.maxWidth = playAgain.width + 50;

	mainMenu.width = 350;
	mainMenu.height = 80;
	mainMenu.x = GetScreenWidth() / 2;
	mainMenu.y = 550;
	mainMenu.initWidth = mainMenu.width;
	mainMenu.maxWidth = mainMenu.width + 50;
}

void updateOptions(CurrentScreen& currentScreen, bool& restart)
{
	if (checkCursorMenuCollision(mainMenu, mainMenu.initWidth, mainMenu.maxWidth) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		restart = true;
		currentScreen = MENU;
	}

	if (checkCursorMenuCollision(playAgain, playAgain.initWidth, playAgain.maxWidth) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		restart = true;
		currentScreen = PLAY;
	}
}

void printOptions()
{
	DrawRectangleGradientH(static_cast<int>(playAgain.x - playAgain.width / 2),
		static_cast<int>(playAgain.y - playAgain.height / 2),
		static_cast<int>(playAgain.width),
		static_cast<int>(playAgain.height), BLUE, DARKPURPLE);

	DrawRectangleGradientH(static_cast<int>(mainMenu.x - mainMenu.width / 2),
		static_cast<int>(mainMenu.y - mainMenu.height / 2),
		static_cast<int>(mainMenu.width),
		static_cast<int>(mainMenu.height), BLUE, DARKPURPLE);


	int playAgainTextX = static_cast<int>(playAgain.x) - static_cast<int>(MeasureText("play again", optionsSize)) / 2;
	int playAgainTextY = playAgain.y - static_cast<int>(MeasureTextEx(GetFontDefault(), "play again", static_cast<float>(optionsSize), 0).y / 2);
	DrawText("play again", playAgainTextX, playAgainTextY, optionsSize, WHITE);


	int mainMenuTextX = static_cast<int>(mainMenu.x) - static_cast<int>(MeasureText("main menu", optionsSize)) / 2;
	int mainMenuTextY = mainMenu.y - static_cast<int>(MeasureTextEx(GetFontDefault(), "main menu", static_cast<float>(optionsSize), 0).y / 2);
	DrawText("main menu", mainMenuTextX, mainMenuTextY, optionsSize, WHITE);
}
}