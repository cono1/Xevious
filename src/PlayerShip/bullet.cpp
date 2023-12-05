#include "bullet.h"

namespace game
{
void initBullet(Bullet& bullet, PlayerShip ship)
{
	bullet.rect.x = ship.pos.x;
	bullet.rect.y = ship.pos.y;
	bullet.rect.width = 15;
	bullet.rect.height = 15;
	bullet.alive = true;
	bullet.speed = 300.f;
	bullet.color = BLACK;
}
//
//void updateBullet(Bullet& bullet)
//{
//
//}
	
void drawBullet(Bullet bullet)
{
	DrawRectangleRec(bullet.rect, bullet.color);
}
}