#include "game.h"

#include "PlayerShip/playerShip.h"

namespace game
{
static PlayerShip ship;

void init();
void update();
void draw();
void deInit();

void loop()
{
	init();
	update();
	deInit();
}

void init()
{
	InitWindow(1024, 768, "Xevious_DanielaGonzalez");
	initPlayerShip(ship);
}

void update()
{
	while (!WindowShouldClose())
	{
		draw();
	}
}

void draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawPlayerShip(ship);

	EndDrawing();
}

void deInit()
{
	deInitPlayerShip(ship);
	CloseWindow();
}
}