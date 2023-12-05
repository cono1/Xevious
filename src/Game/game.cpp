#include "game.h"

#include "PlayerShip/playerShip.h"
#include "PlayerShip/bullet.h"
#include "Enemy/enemy.h"
#include "collisions.h"
#include "Background/background.h"
#include "Sound/sound.h"

namespace game
{
const int maxBullets = 4;

static PlayerShip ship;
static Bullet bullets[maxBullets];
static Enemy enemy;

void updateGame();
void updateGameObjects();
void shoot();

void initGame()
{
	initPlayerShip(ship);
	for (int i = 0; i < maxBullets; i++)
	{
		initBullet(bullets[i], ship);
	}
	initEnmey(enemy);
	initBackground();	
}

void updateGame()
{
	updateGameObjects();

	for (int i = 0; i < maxBullets; i++)
	{
		if (checkCollisions(bullets[i].pos, bullets[i].texture, enemy.pos, enemy.texture) && bullets[i].alive)
		{
			enemy.alive = false;
		}
	}

	if (checkCollisions(ship.pos, ship.texture, enemy.pos, enemy.texture) && enemy.alive)
	{
		ship.alive = false;
		restartBackground();
	}
}

void updateGameObjects()
{
	updateBackground();
	updatePlayerShip(ship);

	for (int i = 0; i < maxBullets; i++)
	{
		updateBullet(bullets[i], ship);
	}

	shoot();
	updateEnemy(enemy);
}

void drawGame()
{
	drawBackground();
	drawEnemy(enemy);
	for (int i = 0; i < maxBullets; i++)
	{
		drawBullet(bullets[i]);
	}
	drawPlayerShip(ship);
}

void deInitGame()
{
	deInitPlayerShip(ship);
	deInitEnemy(enemy);
	for (int i = 0; i < maxBullets; i++)
	{
		deInitBullet(bullets[i]);
	}
	deInitBackground();
}

void shoot()
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (IsKeyPressed(KEY_SPACE) && !bullets[i].alive && ship.alive)
		{
			playShootSound();
			bullets[i].alive = true;
			break;
		}
	}
}
}