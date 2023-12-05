#pragma once

#include "raylib.h"

#include "playerShip.h"

namespace game
{
struct Bullet
{
	Rectangle rect;
	float speed;
	bool alive;
	Color color;
};

void initBullet(Bullet& bullet, PlayerShip ship);
void updateBullet(Bullet& bullet, PlayerShip ship);
void drawBullet(Bullet bullet);
}