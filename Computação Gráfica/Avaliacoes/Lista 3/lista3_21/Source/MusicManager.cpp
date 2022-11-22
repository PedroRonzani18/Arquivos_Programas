#include "../Header/MusicManager.h"

void MusicManager::configureMusic()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    addMusic(Mix_LoadMUS("audio/background1.mp3"));
}