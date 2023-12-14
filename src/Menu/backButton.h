#pragma once

namespace game
{
struct BackButtonRec
{
	int x;
	int y;
	float width;
	float height;
	float initWidth;
	float maxWidth;
};

void initBackButton();
void printBackButton(bool pause, int fontSize);
bool isMouseHoverPause();
}