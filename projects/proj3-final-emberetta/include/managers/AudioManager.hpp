/*
 * AudioManager.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_AUDIOMANAGER_HPP_
#define INCLUDE_AUDIOMANAGER_HPP_

#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <map>
#include <memory>

#include "Util.hpp"


/**
 * A class for managing game resources.  Allows access to resources
 * and makes sure there is only one copy of each resource loaded at a
 * time.
 */
class AudioManager {
private:

	AudioManager(){}  // Private Singleton
	~AudioManager();
	AudioManager(AudioManager const&) = delete; // Avoid copy constructor.
	void operator=(AudioManager const&) = delete; // Don't allow copy assignment.
	AudioManager(AudioManager const&&) = delete; // Avoid move constructor.
	void operator=(AudioManager const&&) = delete; // Don't allow move assignment.

public:

	/**
	 * Returns the texture for the render function to use.
	 * @return instance of the AudioManager
	 */
	static AudioManager& getInstance()
	{
		static AudioManager inst;
		return inst;
	}

	/**
	 * Equivalent to a constructor. Will start the SDL_Mixer
	 * @return 0 on success
	 */
	int startUp();

	/**
	 * Closes the audio mixer.
	 * @return 0 on success
	 */
	int shutDown();

	/**
	 * Plays music, will stop current track and play the one provided, and restart if it's the same.
	 * @param path Filename to play
	 */
	void playMusic(const std::string& path);
	/**
	 * Pauses the music
	 */
	void pauseMusic();

	/**
	 * Plays a sound
	 * @param path Filename to play
	 */
	void playSound(const std::string& path);
};




#endif /* INCLUDE_AUDIOMANAGER_HPP_ */
