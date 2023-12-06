#include "game.h"

#include <time.h>

#include "PlayerShip/playerShip.h"
#include "PlayerShip/bullet.h"
#include "Enemy/enemy.h"
#include "collisions.h"
#include "Background/background.h"
#include "Sound/sound.h"
#include "timer.h"

namespace game
{
const int maxBullets = 4;
const int maxEnemies = 5;

static Timer timer;
static int waitTimeForNewEnemy = 1100;

static PlayerShip ship;
static Bullet bullets[maxBullets];
static Enemy enemies[maxEnemies];

void updateGameObjects();
void shoot();

void initGame()
{
	SetRandomSeed(static_cast<unsigned int>(time(NULL)));

	startTimer(timer);

	initPlayerShip(ship);

	for (int i = 0; i < maxBullets; i++)
	{
		initBullet(bullets[i], ship);
	}

	for (int i = 0; i < maxEnemies; i++)
	{
		initEnemy(enemies[i]);
	}

	initBackground();	
}

void updateGame(CurrentScreen& currentScreen, bool& restart)
{
	updateGameObjects();

	for (int i = 0; i < maxEnemies; i++)
	{
		for (int j = 0; j < maxBullets; j++)
		{
			if (checkCollisions(bullets[j].pos, bullets[j].texture, enemies[i].pos, enemies[i].texture)
				&& bullets[j].alive && enemies[i].alive)
			{
				enemies[i].alive = false;
				bullets[j].alive = false;
			}
		}
	}

	for (int i = 0; i < maxEnemies; i++)
	{
		if (checkCollisions(ship.pos, ship.texture, enemies[i].pos, enemies[i].texture) && enemies[i].alive)
		{
			ship.alive = false;
			initEnemy(enemies[i]);
			initPlayerShip(ship);
			restartBackground();
			currentScreen = LOSE;
		}
	}

	stopTimer(timer);
	for (int i = 0; i < maxEnemies; i++)
	{
		if (getTimeElapsed(timer) >= waitTimeForNewEnemy && !enemies[i].alive)
		{
			initEnemy(enemies[i]);
			enemies[i].alive = true;
			startTimer(timer);
			break;
		}
	}

	if (restart)
	{
		initPlayerShip(ship);
		restartBackground();
		restart = false;
		for (int i = 0; i < maxEnemies; i++)
		{
			initEnemy(enemies[i]);		
		}
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
	for (int i = 0; i < maxEnemies; i++)
	{
		updateEnemy(enemies[i]);
	}
}

void drawGame()
{
	drawBackground();
	for (int i = 0; i < maxEnemies; i++)
	{
		drawEnemy(enemies[i]);
	}

	for (int i = 0; i < maxBullets; i++)
	{
		drawBullet(bullets[i]);
	}
	drawPlayerShip(ship);
}

void deInitGame()
{
	deInitPlayerShip(ship);
	for (int i = 0; i < maxEnemies; i++)
	{
		deInitEnemy(enemies[i]);
	}
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