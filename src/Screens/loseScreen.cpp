#include "loseScreen.h"

#include <string>

#include "raylib.h"

#include "Game/score.h"

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

static std::string scoreText;
static Vector2 scoreTextPos;
static std::string hiScoreText;
static Vector2 hiScoreTextPos;
static std::string globalScoreText;
static Vector2 globalScoreTextPos;

static int scoreSize;
static Color colorScore;

static int optionsSize = 40;

void initOptions();
void printOptions();

void initLoseScreen()
{
	loseText = "You lose";
	loseTextSize = 90;
	loseTextX = (GetScreenWidth() - MeasureText(loseText.c_str(), loseTextSize)) / 2;
	loseTextY = 150;

	scoreSize = 40;
	colorScore = WHITE;
	globalScoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(scoreText.c_str(), scoreSize)) / 2;
	globalScoreTextPos.y = static_cast<float>(loseTextY) + 110;
	hiScoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(scoreText.c_str(), scoreSize)) / 2;
	hiScoreTextPos.y = static_cast<float>(globalScoreTextPos.y) + 50;
	scoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(hiScoreText.c_str(), scoreSize)) / 2;
	scoreTextPos.y = static_cast<float>(hiScoreTextPos.y) + 50;

	initOptions();
}

void updateLoseScreen(CurrentScreen& currentScreen, bool& restart)
{
	scoreText = "Score: " + std::to_string(getScore()); 
	scoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(scoreText.c_str(), scoreSize)) / 2;
	hiScoreText = "High score: " + std::to_string(getHiScore());
	hiScoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(hiScoreText.c_str(), scoreSize)) / 2;
	globalScoreText = "Global score: " + std::to_string(getGlobalScore());
	globalScoreTextPos.x = static_cast<float>((GetScreenWidth()) - MeasureText(globalScoreText.c_str(), scoreSize)) / 2;

	if (checkCursorMenuCollision(mainMenu, mainMenu.initWidth, mainMenu.maxWidth) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ESCAPE))
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
	DrawText(TextFormat(loseText.c_str()), loseTextX, loseTextY, loseTextSize, DARKPURPLE);
	DrawText(scoreText.c_str(), static_cast<int>(scoreTextPos.x), static_cast<int>(scoreTextPos.y), scoreSize, colorScore);
	DrawText(hiScoreText.c_str(), static_cast<int>(hiScoreTextPos.x), static_cast<int>(hiScoreTextPos.y), scoreSize, colorScore);
	DrawText(globalScoreText.c_str(), static_cast<int>(globalScoreTextPos.x), static_cast<int>(globalScoreTextPos.y), scoreSize, colorScore);

	printOptions();
}

void initOptions()
{
	optionsSize = 40;

	playAgain.width = 350;
	playAgain.height = 80;
	playAgain.x = GetScreenWidth() / 2;
	playAgain.y = 470;
	playAgain.initWidth = playAgain.width;
	playAgain.maxWidth = playAgain.width + 50;

	mainMenu.width = 350;
	mainMenu.height = 80;
	mainMenu.x = GetScreenWidth() / 2;
	mainMenu.y = 580;
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