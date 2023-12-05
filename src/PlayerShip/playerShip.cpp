#include "playerShip.h"

#include <iostream>

namespace game
{
void moveLeft(PlayerShip& ship);
void moveRight(PlayerShip& ship);
void moveUp(PlayerShip& ship);
void moveDown(PlayerShip& ship);

void initPlayerShip(PlayerShip& ship)
{
	ship.initPos.x = 500;
	ship.initPos.y = 500;
	ship.pos = ship.initPos;
	ship.color = WHITE;
	ship.texture = LoadTexture("res/tempPlayerShip.png");
	ship.speed = 500;
	ship.lives = 3;
	ship.alive = true;
}

void updatePlayerShip(PlayerShip& ship)
{
	if (IsKeyDown(KEY_UP) && ship.pos.y > 0)
	{
		moveUp(ship);
	}

	if (IsKeyDown(KEY_DOWN) && ship.pos.y + ship.texture.height < GetScreenHeight())
	{
		moveDown(ship);
	}

	if (IsKeyDown(KEY_LEFT) && ship.pos.x > 0)
	{
		moveLeft(ship);
	}

	if (IsKeyDown(KEY_RIGHT) && ship.pos.x + ship.texture.width < GetScreenWidth())
	{
		moveRight(ship);
	}
}

void drawPlayerShip(PlayerShip ship)
{
	DrawTextureV(ship.texture, ship.pos, ship.color);
}

void deInitPlayerShip(PlayerShip& ship)
{
	UnloadTexture(ship.texture);		
}

void moveLeft(PlayerShip& ship)
{
	ship.pos.x -= ship.speed * GetFrameTime();
}

void moveRight(PlayerShip& ship)
{
	ship.pos.x += ship.speed * GetFrameTime();
}

void moveUp(PlayerShip& ship)
{
	ship.pos.y -= ship.speed * GetFrameTime();
}

void moveDown(PlayerShip& ship)
{
	ship.pos.y += ship.speed * GetFrameTime();
}
}