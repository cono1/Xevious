#include "playerShip.h"

namespace game
{
void initPlayerShip(PlayerShip& ship)
{
	ship.initPos.x = 500;
	ship.initPos.y = 500;
	ship.pos = ship.initPos;
	ship.color = WHITE;
	ship.texture = LoadTexture("res/tempPlayerShip.png");
	ship.speed = 10;
	ship.lives = 3;
	ship.alive = true;
}

//void updatePlayerShip(PlayerShip& ship)
//{

//}

void drawPlayerShip(PlayerShip ship)
{
	DrawTextureV(ship.texture, ship.pos, ship.color);
}

void deInitPlayerShip(PlayerShip& ship)
{
	UnloadTexture(ship.texture);		
}
}