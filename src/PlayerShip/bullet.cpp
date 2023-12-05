#include "bullet.h"

namespace game
{
bool checkBulletScreenLimit(Bullet bullet);

void initBullet(Bullet& bullet, PlayerShip ship)
{
	bullet.rect.x = ship.pos.x;
	bullet.rect.y = ship.pos.y;
	bullet.rect.width = 15;
	bullet.rect.height = 15;
	bullet.alive = false;
	bullet.speed = 400.f;
	bullet.color = BLACK;
}

void updateBullet(Bullet& bullet, PlayerShip ship)
{
	if (bullet.alive)
	{
		bullet.rect.y -= bullet.speed * GetFrameTime();
	}
	else
	{
		bullet.rect.x = ship.pos.x;
		bullet.rect.y = ship.pos.y;
	}

	if (checkBulletScreenLimit(bullet))
	{
		bullet.alive = false;
	}
}
	
void drawBullet(Bullet bullet)
{
	if(bullet.alive)
	DrawRectangleRec(bullet.rect, bullet.color);
}

bool checkBulletScreenLimit(Bullet bullet)
{
	return(bullet.rect.y + bullet.rect.height <= 0);
}
}