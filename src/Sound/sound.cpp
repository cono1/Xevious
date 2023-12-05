#include "sound.h"

namespace game
{
static Music gameMusic;
static Sound shootSound;

void initAudio()
{
	InitAudioDevice();

	gameMusic = LoadMusicStream("res/sound_effects/51241__rutgermuller__8-bit-gabber-piece.wav"); //https://freesound.org/people/RutgerMuller/sounds/51241/
	shootSound = LoadSound("res/sound_effects/laserSmall_001.ogg"); //https://kenney.nl/assets/sci-fi-sounds
}

void playGameMusic()
{
	PlayMusicStream(gameMusic);
}

void playShootSound()
{
	PlaySound(shootSound);
}

void deInitAudio()
{
	UnloadMusicStream(gameMusic);
	UnloadSound(shootSound);

	CloseAudioDevice();
}

Music getGameMusic()
{
	return gameMusic;
}
}