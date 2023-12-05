#include "game.h"

#include "PlayerShip/playerShip.h"
#include "Enemy/enemy.h"

namespace game
{
static PlayerShip ship;
static Enemy enemy;

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
	initEnmey(enemy);
}

void update()
{
	while (!WindowShouldClose())
	{
		updatePlayerShip(ship);
		draw();
	}
}

void draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawEnemy(enemy);
	drawPlayerShip(ship);
	
	EndDrawing();
}

void deInit()
{
	deInitPlayerShip(ship);
	deInitEnemy(enemy);
	CloseWindow();
}
}