#pragma once

#include "raylib.h"

namespace game
{
struct PlayerShip
{
	Vector2 initPos;
	Vector2 pos;
	Color color;
	Texture2D texture;
	int width;
	int height;
	float speed;
	int lives;
	bool alive;
};

void initPlayerShip(PlayerShip& ship);
void updatePlayerShip(PlayerShip& ship);
void drawPlayerShip(PlayerShip ship);
void deInitPlayerShip(PlayerShip& ship);
}