/*
 * AudioManger.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: jaked
 */

#include "AudioManager.hpp"
#include "ResourceManager.hpp"
#include <iostream>

AudioManager::~AudioManager() {
    Mix_Quit();
}

int AudioManager::startUp() {
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return 1;
    }
    return 0;
}


int AudioManager::shutDown() {
    Mix_HaltMusic();
    return 0;
}

void AudioManager::playSound(const std::string& path) {
	auto sound = ResourceManager::getInstance().loadSound(path);
	Mix_PlayChannel( -1, sound.get(), 0 );
}

void AudioManager::playMusic(const std::string& path) {
	auto music = ResourceManager::getInstance().loadMusic(path);
	Mix_PlayMusic( music.get(), -1 );
	Mix_VolumeMusic(MIX_MAX_VOLUME/8);

}

void AudioManager::pauseMusic() {

}


