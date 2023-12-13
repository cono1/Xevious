#pragma once

#include "raylib.h"

namespace game
{
void initAudio();
void playGameMusic();
void playMenuMusic();
void playShootSound();
void deInitAudio();
Music getGameMusic();
Music getMenuMusic();
}