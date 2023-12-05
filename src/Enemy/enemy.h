#pragma once

#include "raylib.h"

namespace game
{
struct Enemy
{
	Vector2 initPos;
	Vector2 pos;
	Color color;
	Texture2D texture;
	float speed;
	bool alive;
};

void initEnmey(Enemy& enemy);
//void updateEnemy(Enemy& enemy);
void drawEnemy(Enemy& enemy);
void deInitEnemy(Enemy& enemy);
}