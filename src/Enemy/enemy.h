#pragma once

#include "raylib.h"

namespace game
{
struct Enemy
{
	Texture2D texture;
	Vector2 initPos;
	Vector2 pos;
	Color color;
	int width;
	float speed;
	bool alive;
};

void initEnemy(Enemy& enemy);
void updateEnemy(Enemy& enemy);
void drawEnemy(Enemy& enemy);
void deInitEnemy(Enemy& enemy);
}