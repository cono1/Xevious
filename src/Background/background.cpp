#include "background.h"

#include "raylib.h"

namespace game
{
static Texture2D background;
static float scrollingBackPos;
static float backSpeed;

void initBackground()
{
	background = LoadTexture("res/Unkown Dungeon_Pixelart_Parallax_BG/00.png");

	scrollingBackPos = 0.0f;

	backSpeed = 15.f;
}

void updateBackground()
{
	scrollingBackPos -= backSpeed * GetFrameTime();

	if (scrollingBackPos <= -background.height) scrollingBackPos = 0;
}

void drawBackground()
{
	float scale = 1.0f;
	Color color = WHITE;

	DrawTextureEx(background, { 0, scrollingBackPos }, 0.0f, scale, color);
	DrawTextureEx(background, { 0, background.height + scrollingBackPos }, 0.0f, scale, color);
}

void restartBackground()
{
	scrollingBackPos = 0.0f;
}

void deInitBackground()
{
	UnloadTexture(background);
}
}