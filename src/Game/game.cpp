#include "game.h"

#include "PlayerShip/playerShip.h"
#include "PlayerShip/bullet.h"
#include "Enemy/enemy.h"
#include "collisions.h"
#include "Background/background.h"
#include "Sound/sound.h"

namespace game
{
static PlayerShip ship;
static Bullet bullet;
static Enemy enemy;

void updateGame();
void updateGameObjects();
void shoot();

void initGame()
{
	initPlayerShip(ship);
	initBullet(bullet, ship);
	initEnmey(enemy);
	initBackground();	
}

void updateGame()
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
}

void updateGameObjects()
{
	updateBackground();
	updatePlayerShip(ship);
	updateBullet(bullet, ship);
	shoot();
	updateEnemy(enemy);
}

void drawGame()
{
	drawBackground();
	drawEnemy(enemy);
	drawBullet(bullet);
	drawPlayerShip(ship);
}

void deInitGame()
{
	deInitPlayerShip(ship);
	deInitEnemy(enemy);
	deInitBullet(bullet);
	deInitBackground();
}

void shoot()
{
	if (IsKeyPressed(KEY_SPACE) && !bullet.alive && ship.alive)
	{
		playShootSound();
		bullet.alive = true;
	}
}
}