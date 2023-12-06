#include "enemy.h"

#include "raylib.h"

#include "Animations/animation.h"

namespace game
{
static Animation enemyAnimation;
static int totalSprites = 4;

bool checkEnemyScreenLimit(Enemy enemy);

void initEnemy(Enemy& enemy)
{
	enemy.texture = LoadTexture("res/Enemy/enemySpritesheet.png");//https://www.gamedevmarket.net/asset/mobs-creatures-animals
	enemy.initPos.x = static_cast<float>(GetRandomValue(0, GetScreenWidth() - enemy.texture.width));
	enemy.initPos.y = 5;
	enemy.pos = enemy.initPos;
	enemy.color = WHITE;
	enemy.width = enemy.texture.width / totalSprites;
	enemy.speed = 200;
	enemy.alive = true;

	initAnimation(enemyAnimation, static_cast<float>(enemy.texture.width), static_cast<float>(enemy.texture.height), totalSprites);
}

void updateEnemy(Enemy& enemy)
{
	if (enemy.alive)
	{
		enemy.pos.y += enemy.speed * GetFrameTime();
		updateAnimation(enemyAnimation, static_cast<float>(enemy.texture.width));

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
		Rectangle dest = { enemy.pos.x + 10 + enemy.width / 2, enemy.pos.y + enemy.texture.height / 2,
						   static_cast<float>(enemy.texture.width / totalSprites), 
						   static_cast<float>(enemy.texture.height) };

		Vector2 origin = { static_cast<float>(enemy.texture.width / totalSprites / 2),
						   static_cast<float>(enemy.texture.height / 2) };

		DrawTexturePro(enemy.texture, getFrameRect(enemyAnimation), dest, origin, 0, enemy.color);

#ifdef _DEBUG
		DrawRectangleLines(static_cast<int>(enemy.pos.x), static_cast<int>(enemy.pos.y), enemy.width, enemy.texture.height, enemy.color);
#endif
		//DrawTextureV(enemy.texture, enemy.pos, enemy.color);
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