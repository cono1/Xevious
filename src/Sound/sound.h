#pragma once

#include "raylib.h"

namespace game
{
void initAudio();
void playGameMusic();
void playShootSound();
void deInitAudio();
Music getGameMusic();
}