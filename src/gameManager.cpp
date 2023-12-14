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
void updateGameScreens();
void drawGameScreens();
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
	SetExitKey(NULL);

	while (!WindowShouldClose() && !closeGame)
	{		
		updateGameScreens();
		drawGameScreens();		
	}
}

void updateGameScreens()
{
	switch (currentScreen)
	{
	case game::PLAY:
		updateGame(currentScreen, prevScreen, restart);
		break;
	case game::RULES:
		updateRules();
		break;
	case game::CREDITS:
		updateCredits();
		break;
	case game::EXIT:
		return;
		break;
	case game::MENU:
	case game::PAUSE:
		updateMenu(currentScreen, prevScreen, closeGame);
		break;
	case game::LOSE:
		updateLoseScreen(currentScreen, restart);
		break;
	default:
		break;
	}
}

void drawGameScreens()
{
	BeginDrawing();
	ClearBackground(GOLD);

	switch (currentScreen)
	{
	case game::PLAY:
		drawGame();
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
		printMenu("Xyphoria", "play");
		break;
	case game::PAUSE:
		printMenu("Paused", "resume");
		break;
	case game::LOSE:
		printLoseScreen();
		break;
	default:
		break;
	}

	EndDrawing();
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