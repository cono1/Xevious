#include "collisions.h"

namespace game
{
bool checkCollisions(Vector2 pos1, Texture texture1, Vector2 pos2, int width, int height)
{
	return (pos1.x + texture1.width >= pos2.x &&
		    pos1.x <= pos2.x + width &&
		    pos1.y + texture1.height >= pos2.y &&
		    pos1.y <= pos2.y + height);
}
}