#pragma once

#include "raylib.h"

namespace game
{
void initAudio();
void playGameMusic();
void deInitAudio();
Music getGameMusic();
}