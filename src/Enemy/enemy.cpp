#include "enemy.h"

namespace game
{
bool checkEnemyScreenLimit(Enemy enemy);

void initEnmey(Enemy& enemy)
{
	enemy.texture = LoadTexture("res/tempEnemyShip.png");
	enemy.initPos.x = 500;
	enemy.initPos.y = 10;
	enemy.pos = enemy.initPos;
	enemy.color = WHITE;
	enemy.speed = 200;
	enemy.alive = true;
}

void updateEnemy(Enemy& enemy)
{
	if (enemy.alive)
	{
		enemy.pos.y += enemy.speed * GetFrameTime();

		if (checkEnemyScreenLimit(enemy))
		{
			enemy.alive = false;
		}
	}
}
	
void drawEnemy(Enemy& enemy)
{
	if (enemy.alive)
	{
		DrawTextureV(enemy.texture, enemy.pos, enemy.color);
	}
}
	
void deInitEnemy(Enemy& enemy)
{
	UnloadTexture(enemy.texture);
}

bool checkEnemyScreenLimit(Enemy enemy)
{
	return(enemy.pos.y >= GetScreenHeight());
}
}