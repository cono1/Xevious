#include "game.h"

#include "PlayerShip/playerShip.h"
#include "PlayerShip/bullet.h"
#include "Enemy/enemy.h"
#include "collisions.h"
#include "Background/background.h"

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
	initBackground();
}

void update()
{
	while (!WindowShouldClose())
	{
		updateGameObjects();

		if (checkCollisions(bullet.pos, bullet.texture, enemy.pos, enemy.texture) && bullet.alive)
		{
			enemy.alive = false;
		}

		if (checkCollisions(ship.pos, ship.texture, enemy.pos, enemy.texture) && enemy.alive)
		{
			ship.alive = false;
			restartBackground();
		}

		draw();
	}
}

void updateGameObjects()
{
	updateBackground();
	updatePlayerShip(ship);
	updateBullet(bullet, ship);
	shoot();
	updateEnemy(enemy);
}

void draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawBackground();
	drawEnemy(enemy);
	drawBullet(bullet);
	drawPlayerShip(ship);
	
	EndDrawing();
}

void deInit()
{
	deInitPlayerShip(ship);
	deInitEnemy(enemy);
	deInitBullet(bullet);
	deInitBackground();
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