#pragma once

#include "raylib.h"

namespace game
{
bool checkCollisions(Vector2 pos1, int width1, int height1, Vector2 pos2, int width2, int height2);
}