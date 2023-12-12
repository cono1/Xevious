#include "loseScreen.h"

#include <string>

#include "raylib.h"

namespace game
{
static MenuRect playAgain;
static MenuRect mainMenu;

static std::string loseText;
static int loseTextSize;
static int loseTextX;
static int loseTextY;

static int playAgainTextX;
static int playAgainTextY;

static int mainMenuTextX;
static int mainMenuTextY;

std::string scoreText;
Vector2 scoreTextPos;
int scoreSize;
Color colorScore;

static int optionsSize = 40;

void initOptions();
void printOptions();

void initLoseScreen()
{
	loseText = "You lose";
	loseTextSize = 80;
	loseTextX = (GetScreenWidth() - MeasureText(loseText.c_str(), loseTextSize)) / 2;
	loseTextY = 200;

	scoreSize = 40;
	colorScore = WHITE;
	scoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(scoreText.c_str(), scoreSize)) / 2;
	scoreTextPos.y = static_cast<float>(loseTextY) + 80;

	initOptions();
}

void updateLoseScreen(CurrentScreen& currentScreen, bool& restart, int score)
{
	scoreText = "Score: " + std::to_string(score); 
	scoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(scoreText.c_str(), scoreSize)) / 2;

	if (checkCursorMenuCollision(mainMenu, mainMenu.initWidth, mainMenu.maxWidth) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		restart = true;
		currentScreen = MENU;
	}

	if (checkCursorMenuCollision(playAgain, playAgain.initWidth, playAgain.maxWidth) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
	{
		restart = true;
		currentScreen = PLAY;
	}
}

void printLoseScreen()
{
	DrawText(TextFormat(loseText.c_str()), loseTextX, loseTextY, loseTextSize, WHITE);
	DrawText(scoreText.c_str(), static_cast<int>(scoreTextPos.x), static_cast<int>(scoreTextPos.y), scoreSize, colorScore);

	printOptions();
}

void initOptions()
{
	optionsSize = 40;

	playAgain.width = 350;
	playAgain.height = 80;
	playAgain.x = GetScreenWidth() / 2;
	playAgain.y = 400;
	playAgain.initWidth = playAgain.width;
	playAgain.maxWidth = playAgain.width + 50;

	mainMenu.width = 350;
	mainMenu.height = 80;
	mainMenu.x = GetScreenWidth() / 2;
	mainMenu.y = 550;
	mainMenu.initWidth = mainMenu.width;
	mainMenu.maxWidth = mainMenu.width + 50;
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


	playAgainTextX = static_cast<int>(playAgain.x) - static_cast<int>(MeasureText("play again", optionsSize)) / 2;
	playAgainTextY = playAgain.y - static_cast<int>(MeasureTextEx(GetFontDefault(), "play again", static_cast<float>(optionsSize), 0).y / 2);
	DrawText("play again", playAgainTextX, playAgainTextY, optionsSize, WHITE);


	mainMenuTextX = static_cast<int>(mainMenu.x) - static_cast<int>(MeasureText("main menu", optionsSize)) / 2;
	mainMenuTextY = mainMenu.y - static_cast<int>(MeasureTextEx(GetFontDefault(), "main menu", static_cast<float>(optionsSize), 0).y / 2);
	DrawText("main menu", mainMenuTextX, mainMenuTextY, optionsSize, WHITE);
}
}