#include "menu.h"

#include <string>
#include <iostream>

#include <raylib.h>

namespace game
{
const int maxMenuRects = 4;
const int maxGameOverRects = 2;
static MenuRect menuRect[maxMenuRects];
static MenuRect pauseRect;

void writeOnMenuSquare(std::string word, int pos, int fontSize);
bool checkMenuInput(CurrentScreen currentSquare);

void initMenu(const int screenWidth)
{
	int spaceBetweenRects = 20;
	int firstRectYPosition = 300;

	for (int i = 0; i < maxMenuRects; i++)
	{
		menuRect[i].width = 450;
		menuRect[i].height = 80;
		menuRect[i].x = (screenWidth - menuRect[i].x) / 2;
		menuRect[i].y = static_cast<int>(firstRectYPosition + (menuRect[i].height + spaceBetweenRects) * i);
		menuRect[i].initWidth = menuRect[i].width;
		menuRect[i].maxWidth = menuRect[i].width + 20;
	}

	pauseRect.x = 40;
	pauseRect.y = 15;
	pauseRect.width = 35;
	pauseRect.height = 35;
	pauseRect.initWidth = pauseRect.width;
	pauseRect.maxWidth = pauseRect.width + 10;
}

void updateMenu(CurrentScreen& currentScreen)
{
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

void printMenu(std::string title, std::string firstOption, int titleSize, int optionsSize)
{
	DrawText(TextFormat(title.c_str()), (GetScreenWidth() - MeasureText(title.c_str(), titleSize)) / 2, 100, titleSize, WHITE);

	for (int i = 0; i < maxMenuRects; i++)
	{
		DrawRectangleGradientH(static_cast<int>(menuRect[i].x - menuRect[i].width / 2),
			static_cast<int>(menuRect[i].y - menuRect[i].height / 2),
			static_cast<int>(menuRect[i].width),
			static_cast<int>(menuRect[i].height), BLUE, DARKPURPLE);

		if (i == PLAY)
			writeOnMenuSquare(firstOption, i, optionsSize);

		if (i == RULES)
			writeOnMenuSquare("how to play", i, optionsSize);

		if (i == CREDITS)
			writeOnMenuSquare("credits", i, optionsSize);

		if (i == EXIT)
			writeOnMenuSquare("exit", i, optionsSize);
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

void printBackButton(bool pause, int fontSize)
{
	DrawRectangleGradientH(static_cast<int>(pauseRect.x - pauseRect.width / 2),
		static_cast<int>(pauseRect.y - pauseRect.height / 2),
		static_cast<int>(pauseRect.width),
		static_cast<int>(pauseRect.height), BLUE, DARKPURPLE);

	if (pause)
		DrawText("||", pauseRect.x, pauseRect.y - 10, fontSize, WHITE);
	else
		DrawText("<-", pauseRect.x, pauseRect.y - 10, fontSize, WHITE);
}

bool isMouseHoverPause()
{
	return checkCursorMenuCollision(pauseRect, pauseRect.initWidth, pauseRect.maxWidth);
}

void writeOnMenuSquare(std::string word, int pos, int fontSize)
{
	int xOffsetText = static_cast<int>(menuRect[pos].x) - static_cast<int>(MeasureText(word.c_str(), fontSize)) / 2;
	int yOffsetText = static_cast<int>((menuRect[pos].height - fontSize / 2) / 2);

	DrawText(word.c_str(), xOffsetText, menuRect[pos].y - yOffsetText, fontSize, WHITE);
}

bool checkMenuInput(CurrentScreen currentSquare)
{
	return (checkCursorMenuCollision(menuRect[currentSquare], menuRect[currentSquare].initWidth,
		menuRect[currentSquare].maxWidth) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}
}