#include "gameManager.h"

#include <iostream>

#include "raylib.h"

#include "Menu/menu.h"
#include "Menu/backButton.h"
#include "Game/game.h"
#include "Game/score.h"
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

void updatePlayState();
void updateMenuAndPauseStates();
void drawPlayState();
void drawRulesState();
void checkGoBack();

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

	InitWindow(screenWidth, screenHeight, "Xyphoria_DanielaGonzalez");

	currentScreen = MENU;
	initAudio();
	SetMusicVolume(getGameMusic(), 0.5f);
	initGame();
	initMenu(screenWidth);
	initBackButton();
	initCredits();
	initRules();
	initLoseScreen();
	initScore();
}

void updateGameManager()
{
	int titleSize = 80;
	int optionsSize = 50;

	SetExitKey(NULL);

	while (!WindowShouldClose() && !closeGame)
	{		
		//update
		switch (currentScreen)
		{
		case game::PLAY:
			updatePlayState();
			break;
		case game::RULES:
			checkGoBack();
			break;
		case game::CREDITS:
			updateCredits();
			checkGoBack();
			break;
		case game::EXIT:
			return;
			break;
		case game::MENU:
		case game::PAUSE:
			updateMenuAndPauseStates();
			break;
		case game::LOSE:
			updateLoseScreen(currentScreen, restart);
			break;
		default:
			break;
		}

		//drawing
		BeginDrawing();
		ClearBackground(GOLD);

		switch (currentScreen)
		{
		case game::PLAY:
			drawPlayState();
			break;
		case game::RULES:
			printRules();
			break;
		case game::CREDITS:
			printCredits();
			break;
		case game::EXIT:
			break;
		case game::MENU:
			printMenu("Xyphoria", "play", titleSize, optionsSize);
			break;
		case game::PAUSE:
			printMenu("Paused", "resume", titleSize, optionsSize);
			break;
		case game::LOSE:
			printLoseScreen();
			break;
		default:
			break;
		}

		EndDrawing();
	}
}

void updatePlayState()
{
	prevScreen = currentScreen;
	playGameMusic();
	UpdateMusicStream(getGameMusic());
	checkGoBack();
	updateGame(currentScreen, restart);
	updateScore();
}

void updateMenuAndPauseStates()
{
	playMenuMusic();
	UpdateMusicStream(getMenuMusic());
	prevScreen = currentScreen;
	if (IsKeyPressed(KEY_ESCAPE))
	{
		closeGame = true;
	}
	updateMenu(currentScreen);
}

void drawPlayState()
{
	drawGame();
	drawScore();
	printBackButton(true);
}

void checkGoBack()
{
	if (isMouseHoverPause() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ESCAPE))
	{
		if (prevScreen == PAUSE || prevScreen == PLAY) currentScreen = PAUSE;
		if (prevScreen == MENU) currentScreen = MENU;
	}
}

void deInitGameManager()
{
	deInitAudio();
	deInitGame();
	CloseWindow();
}
}