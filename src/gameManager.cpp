#include "gameManager.h"

#include "raylib.h"

#include "Menu/menu.h"
#include "Game/game.h"
#include "Sound/sound.h"

namespace game
{
CurrentScreen currentScreen;

void initGameManager();
void updateGameManager();
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

	while (!WindowShouldClose())
	{
		switch (currentScreen)
		{
		case game::PLAY:
			playGameMusic();
			UpdateMusicStream(getGameMusic());

			if (isMouseHoverPause() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				PauseMusicStream(getGameMusic());
				currentScreen = PAUSE;
			}

			updateGame();

			BeginDrawing();
			ClearBackground(RAYWHITE);
			drawGame();
			printBackButton(true, pauseSize);
			EndDrawing();
			break;
		case game::RULES:
			break;
		case game::CREDITS:
			break;
		case game::EXIT:
			return;
			break;
		case game::MENU:
			updateMenu(currentScreen);
			BeginDrawing();
			ClearBackground(GOLD);
			printMenu("Xevious", "play", titleSize, optionsSize);
			EndDrawing();
			break;
		case game::PAUSE:
			updateMenu(currentScreen);
			BeginDrawing();
			ClearBackground(GOLD);
			printMenu("Paused", "resume", titleSize, optionsSize);
			EndDrawing();
			break;
		default:
			break;
		}
	}
}

void deInitGameManager()
{
	deInitAudio();
	deInitGame();
	CloseWindow();
}
}