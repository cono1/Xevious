#include "enemy.h"

namespace game
{
void initEnmey(Enemy& enemy)
{
	enemy.texture = LoadTexture("res/tempEnemyShip.png");
	enemy.initPos.x = 500;
	enemy.initPos.y = 10;
	enemy.pos = enemy.initPos;
	enemy.color = WHITE;
	enemy.speed = 200;
	enemy.alive = false;
}

//void updateEnemy(Enemy& enemy)
//{
//
//}
	
void drawEnemy(Enemy& enemy)
{
	DrawTextureV(enemy.texture, enemy.pos, enemy.color);
}
	
void deInitEnemy(Enemy& enemy)
{
	UnloadTexture(enemy.texture);
}
}