#include "playerShip.h"

#include <iostream>

#include "Animations/animation.h"

namespace game
{
static Animation playerAnimation;
static int totalSprites = 3;

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
	ship.texture = LoadTexture("res/Player/playerSpriteSheet.png"); //https://www.gamedevmarket.net/asset/animated-emojis
	ship.width = ship.texture.width / totalSprites - 40;
	ship.height = ship.texture.height - 30;
	ship.speed = 500;
	ship.lives = 3;
	ship.alive = true;

	initAnimation(playerAnimation, static_cast<float>(ship.texture.width), static_cast<float>(ship.texture.height), totalSprites);
}

void updatePlayerShip(PlayerShip& ship)
{
	if (ship.alive)
	{
		if (IsKeyDown(KEY_UP) && ship.pos.y > 0)
		{
			moveUp(ship);
		}

		if (IsKeyDown(KEY_DOWN) && ship.pos.y + ship.height < GetScreenHeight())
		{
			moveDown(ship);
		}

		if (IsKeyDown(KEY_LEFT) && ship.pos.x > 0)
		{
			moveLeft(ship);
		}

		if (IsKeyDown(KEY_RIGHT) && ship.pos.x + ship.width < GetScreenWidth())
		{
			moveRight(ship);
		}

		updateAnimation(playerAnimation, static_cast<float>(ship.texture.width));
	}
}

void drawPlayerShip(PlayerShip ship)
{
	if (ship.alive)
	{
		Rectangle dest = { ship.pos.x + ship.width / 2, ship.pos.y + ship.height / 2,
						   static_cast<float>(ship.texture.width / totalSprites),
						   static_cast<float>(ship.texture.height) };

		Vector2 origin = { static_cast<float>(ship.texture.width / totalSprites / 2),
						   static_cast<float>(ship.texture.height / 2) };

		DrawTexturePro(ship.texture, getFrameRect(playerAnimation), dest, origin, 0, ship.color);

#ifdef _DEBUG
		DrawRectangleLines(static_cast<int>(ship.pos.x), static_cast<int>(ship.pos.y), ship.width, ship.height, ship.color);
#endif
	}
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