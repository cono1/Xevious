#include "collisions.h"

namespace game
{
bool checkCollisions(Vector2 pos1, int width1, int height1, Vector2 pos2, int width2, int height2)
{
	return (pos1.x + width1 >= pos2.x &&
		    pos1.x <= pos2.x + width2 &&
		    pos1.y + height1 >= pos2.y &&
		    pos1.y <= pos2.y + height2);
}
}