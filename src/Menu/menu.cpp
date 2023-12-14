#include "menu.h"

#include <string>
#include <iostream>

#include <raylib.h>

#include "Sound/sound.h"

namespace game
{
const int maxMenuRects = 4;
const int maxGameOverRects = 2;
static MenuRect menuRect[maxMenuRects];

static int optionsSize;

void writeOnMenuSquare(std::string word, int pos);
bool checkMenuInput(CurrentScreen currentSquare);

void initMenu(const int screenWidth)
{
	int spaceBetweenRects = 20;
	int firstRectYPosition = 300;
	optionsSize = 50;

	for (int i = 0; i < maxMenuRects; i++)
	{
		menuRect[i].width = 450;
		menuRect[i].height = 80;
		menuRect[i].x = (screenWidth - menuRect[i].x) / 2;
		menuRect[i].y = static_cast<int>(firstRectYPosition + (menuRect[i].height + spaceBetweenRects) * i);
		menuRect[i].initWidth = menuRect[i].width;
		menuRect[i].maxWidth = menuRect[i].width + 20;
	}
}

void updateMenu(CurrentScreen& currentScreen, CurrentScreen& prevScreen, bool& closeGame)
{
	playMenuMusic();
	UpdateMusicStream(getMenuMusic());
	prevScreen = currentScreen;

	if (IsKeyPressed(KEY_ESCAPE))
	{
		closeGame = true;
	}

	if (checkMenuInput(PLAY) || IsKeyPressed(KEY_ENTER))
	{
		currentScreen = PLAY;
	}

	if (checkMenuInput(PAUSE))
	{
		currentScreen = PAUSE;
	}

	if (checkMenuInput(RULES))
	{
		currentScreen = RULES;
	}

	if (checkMenuInput(CREDITS))
	{
		currentScreen = CREDITS;
	}

	if (checkMenuInput(EXIT))
	{
		currentScreen = EXIT;
	}
}

void printMenu(std::string title, std::string firstOption)
{
	int titleSize = 80;

	DrawText(TextFormat(title.c_str()), (GetScreenWidth() - MeasureText(title.c_str(), titleSize)) / 2, 100, titleSize, WHITE);

	for (int i = 0; i < maxMenuRects; i++)
	{
		DrawRectangleGradientH(static_cast<int>(menuRect[i].x - menuRect[i].width / 2),
			static_cast<int>(menuRect[i].y - menuRect[i].height / 2),
			static_cast<int>(menuRect[i].width),
			static_cast<int>(menuRect[i].height), BLUE, DARKPURPLE);

		if (i == PLAY)
			writeOnMenuSquare(firstOption, i);

		if (i == RULES)
			writeOnMenuSquare("how to play", i);

		if (i == CREDITS)
			writeOnMenuSquare("credits", i);

		if (i == EXIT)
			writeOnMenuSquare("exit", i);
	}
}

bool checkCursorMenuCollision(MenuRect& menuRec, float initWidth, float maxWidth)
{
	int mouseX = static_cast<int>(GetMousePosition().x);
	int mouseY = static_cast<int>(GetMousePosition().y);

	if (mouseX >= menuRec.x - menuRec.width / 2 &&
		mouseX <= menuRec.x + menuRec.width / 2 &&
		mouseY >= menuRec.y - menuRec.height / 2 &&
		mouseY <= menuRec.y + menuRec.height / 2)
	{
		if (menuRec.width < maxWidth)
			menuRec.width += 5;

		return true;
	}
	else
	{
		menuRec.width = initWidth;
		return false;
	}
}

void writeOnMenuSquare(std::string word, int pos)
{
	int xOffsetText = static_cast<int>(menuRect[pos].x) - static_cast<int>(MeasureText(word.c_str(), optionsSize)) / 2;
	int yOffsetText = static_cast<int>((menuRect[pos].height - optionsSize / 2) / 2);

	DrawText(word.c_str(), xOffsetText, menuRect[pos].y - yOffsetText, optionsSize, WHITE);
}

bool checkMenuInput(CurrentScreen currentSquare)
{
	return (checkCursorMenuCollision(menuRect[currentSquare], menuRect[currentSquare].initWidth,
		menuRect[currentSquare].maxWidth) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}
}