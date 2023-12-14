#include "backButton.h"

#include "raylib.h"

namespace game
{
static BackButtonRec pauseRect;
static int fontSize;

void initBackButton()
{
	pauseRect.x = 40;
	pauseRect.y = 20;
	pauseRect.width = 35;
	pauseRect.height = 35;
	pauseRect.initWidth = pauseRect.width;
	pauseRect.maxWidth = pauseRect.width + 10;

	fontSize = 20;
}

void printBackButton(bool pause)
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
	int mouseX = static_cast<int>(GetMousePosition().x);
	int mouseY = static_cast<int>(GetMousePosition().y);

	if (mouseX >= pauseRect.x - pauseRect.width / 2 &&
		mouseX <= pauseRect.x + pauseRect.width / 2 &&
		mouseY >= pauseRect.y - pauseRect.height / 2 &&
		mouseY <= pauseRect.y + pauseRect.height / 2)
	{
		if (pauseRect.width < pauseRect.maxWidth)
			pauseRect.width += 5;

		return true;
	}
	else
	{
		pauseRect.width = pauseRect.initWidth;
		return false;
	}
}
}