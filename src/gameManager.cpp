#include "gameManager.h"

#include <iostream>

#include "raylib.h"

#include "Menu/menu.h"
#include "Game/game.h"
#include "Sound/sound.h"

#include "Screens/loseScreen.h"
#include "Screens/rulesScreen.h"
#include "Screens/credits.h"

namespace game
{
CurrentScreen currentScreen;
static CurrentScreen prevScreen;

bool restart = false;
static bool closeGame = false;

void initGameManager();
void updateGameManager();

void drawScore(int score);
void deInitGameManager();

void gameLoop()
{
	initGameManager();
	updateGameManager();
	deInitGameManager();
}

void initGameManager()
{
	const int screenWidth = 1024;
	const int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "Xevious_DanielaGonzalez");

	currentScreen = MENU;
	initAudio();
	SetMusicVolume(getGameMusic(), 0.2f);
	initGame();
	initMenu(screenWidth);
}

void updateGameManager()
{
	int titleSize = 80;
	int optionsSize = 50;
	int pauseSize = 20;
	int score = 0;

	SetExitKey(NULL);

	while (!WindowShouldClose() && !closeGame)
	{		
		switch (currentScreen)
		{
		case game::PLAY:
			prevScreen = currentScreen;
			playGameMusic();
			UpdateMusicStream(getGameMusic());

			if (isMouseHoverPause() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				PauseMusicStream(getGameMusic());
				currentScreen = PAUSE;
			}

			updateGame(currentScreen, restart, score);

			BeginDrawing();
			ClearBackground(RAYWHITE);
			drawGame();
			drawScore(score);
			printBackButton(true, pauseSize);
			EndDrawing();
			break;
		case game::RULES:
			if (isMouseHoverPause() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if(prevScreen == PAUSE) currentScreen = PAUSE;
				if (prevScreen == MENU) currentScreen = MENU;
			}
			BeginDrawing();
			ClearBackground(GOLD);
			printBackButton(false, pauseSize);
			printRules();
			EndDrawing();
			break;
		case game::CREDITS:
			if (isMouseHoverPause() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (prevScreen == PAUSE) currentScreen = PAUSE;
				if (prevScreen == MENU) currentScreen = MENU;
			}
			BeginDrawing();
			ClearBackground(GOLD);
			printBackButton(false, pauseSize);
			printCredits();
			EndDrawing();
			break;
		case game::EXIT:
			return;
			break;
		case game::MENU:
			prevScreen = currentScreen;
			if (IsKeyPressed(KEY_ESCAPE))
			{
				closeGame = true;
			}
			updateMenu(currentScreen);
			BeginDrawing();
			ClearBackground(GOLD);
			printMenu("Xevious", "play", titleSize, optionsSize);
			EndDrawing();
			break;
		case game::PAUSE:
			prevScreen = currentScreen;
			if (IsKeyPressed(KEY_ESCAPE))
			{
				closeGame = true;
			}
			updateMenu(currentScreen);
			BeginDrawing();
			ClearBackground(GOLD);
			printMenu("Paused", "resume", titleSize, optionsSize);
			EndDrawing();
			break;
		case game::LOSE:
			BeginDrawing();
			ClearBackground(GOLD);
			printLoseScreen(currentScreen, restart);
			EndDrawing();
			break;
		default:
			break;
		}
	}
}

void drawScore(int score)
{
	
	Vector2 scoreTextPos;
	int scoreSize = 30;
	Color colorScore = WHITE;
	scoreTextPos.x = static_cast<float>(GetScreenWidth()) - static_cast<float>((MeasureTextEx(GetFontDefault(), "SCORE:  000000", static_cast<float>(scoreSize), 0).x));
	scoreTextPos.y = 10;

	std::string scoreText = "Score: " + std::to_string(score);
	DrawText(scoreText.c_str(), static_cast<int>(scoreTextPos.x), static_cast<int>(scoreTextPos.y), scoreSize, colorScore);
}


void deInitGameManager()
{
	deInitAudio();
	deInitGame();
	CloseWindow();
}
}