#include "sound.h"

namespace game
{
static Music gameMusic;

void initAudio()
{
	InitAudioDevice();

	gameMusic = LoadMusicStream("res/sound_effects/51241__rutgermuller__8-bit-gabber-piece.wav"); //https://freesound.org/people/RutgerMuller/sounds/51241/
}

void playGameMusic()
{
	PlayMusicStream(gameMusic);
}

void deInitAudio()
{
	UnloadMusicStream(gameMusic);

	CloseAudioDevice();
}

Music getGameMusic()
{
	return gameMusic;
}
}