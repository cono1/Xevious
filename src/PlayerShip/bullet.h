#pragma once

#include "raylib.h"

#include "playerShip.h"

namespace game
{
struct Bullet
{
	Texture texture;
	Vector2 pos;
	float speed;
	bool alive;
	Color color;
};

void initBullet(Bullet& bullet, PlayerShip ship);
void updateBullet(Bullet& bullet, PlayerShip ship);
void drawBullet(Bullet bullet);
void deInitBullet(Bullet& bullet);
}