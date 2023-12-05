#include "game.h"

#include "PlayerShip/playerShip.h"
#include "PlayerShip/bullet.h"
#include "Enemy/enemy.h"

namespace game
{
static PlayerShip ship;
static Bullet bullet;
static Enemy enemy;

void init();
void update();
void updateGameObjects();
void draw();
void deInit();

void shoot();

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
	initBullet(bullet, ship);
	initEnmey(enemy);
}

void update()
{
	while (!WindowShouldClose())
	{
		updateGameObjects();
		draw();
	}
}

void updateGameObjects()
{
	updatePlayerShip(ship);
	updateBullet(bullet, ship);
	shoot();
	updateEnemy(enemy);
}

void draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawEnemy(enemy);
	drawBullet(bullet);
	drawPlayerShip(ship);
	
	EndDrawing();
}

void deInit()
{
	deInitPlayerShip(ship);
	deInitEnemy(enemy);
	CloseWindow();
}

void shoot()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
	{
		bullet.alive = true;
	}
}
}