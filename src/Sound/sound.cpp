#include "sound.h"

namespace game
{
static Music gameMusic;
static Music menuMusic;
static Sound shootSound;

void initAudio()
{
	InitAudioDevice();

	gameMusic = LoadMusicStream("res/sound_effects/51241__rutgermuller__8-bit-gabber-piece.wav"); //https://freesound.org/people/RutgerMuller/sounds/51241/
	menuMusic = LoadMusicStream("res/sound_effects/pixel-song.mp3"); //https://pixabay.com/sound-effects/026491-pixel-song-8-72675/
	shootSound = LoadSound("res/sound_effects/laserSmall_001.ogg"); //https://kenney.nl/assets/sci-fi-sounds
}

void playGameMusic()
{
	PlayMusicStream(gameMusic);
}

void playMenuMusic()
{
	PlayMusicStream(menuMusic);
}

void playShootSound()
{
	PlaySound(shootSound);
}

void deInitAudio()
{
	UnloadMusicStream(gameMusic);
	UnloadMusicStream(menuMusic);
	UnloadSound(shootSound);

	CloseAudioDevice();
}

Music getGameMusic()
{
	return gameMusic;
}

Music getMenuMusic()
{
	return menuMusic;
}
}