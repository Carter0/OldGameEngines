#pragma once

/*
 * ResourceManager.hpp
 *
 *  Created on: Feb 8, 2020
 *  Author: Carter Weinberg
 */

#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "platformance/objects/Enemy.hpp"
#include "platformance/objects/Goal.hpp"
#include "platformance/objects/GameController.hpp"


#include "Util.hpp"
#include "platformance/Platformance.hpp"

class Brick;
class Player;
//class Enemy;

/**
 * A class for managing game resources.  Allows access to resources
 * and makes sure there is only one copy of each resource loaded at a
 * time.
 */
class ResourceManager {
private:

	ResourceManager() {
	}  // Private Singleton
	ResourceManager(ResourceManager const&) = delete; // Avoid copy constructor.
	void operator=(ResourceManager const&) = delete; // Don't allow copy assignment.
	ResourceManager(ResourceManager const&&) = delete; // Avoid move constructor.
	void operator=(ResourceManager const&&) = delete; // Don't allow move assignment.

	std::shared_ptr<SDL_Renderer> renderer;

	/**
	 * The collection that will hold our resource.
	 * It will be from the string path to the SDL_texture.
	 */
	std::map<std::string, std::shared_ptr<SDL_Texture>> textures;

	/**
	 * Holds a reference to the fonts we are using for our game.
	 */
	std::map<std::string, std::shared_ptr<TTF_Font>> fonts;

	/**
	 * Holds Music Files
	 */
	std::map<std::string, std::shared_ptr<Mix_Music>> musics;

	/**
	 * Holds a reference to the sounds we are using for our game.
	 */
	std::map<std::string, std::shared_ptr<Mix_Chunk>> sounds;
public:

	/**
	 * Returns the texture for the render function to use.
	 */
	static ResourceManager& getInstance() {
		static ResourceManager inst;
		return inst;
	}

	/**
	 * Equivalent to a constructor.
	 */
	int startUp(std::shared_ptr<SDL_Renderer> rend);

	/**
	 * Equivalent to a destructor.
	 * Will go through the map and free the SDL textures allocated.
	 */
	int shutDown();

	/**
	 * Lookup the texture to see if it was already allocated in the map.
	 * If it was, find the resource and return it, otherwise, allocate a new resource and add it to the map.
	 */
	std::shared_ptr<SDL_Texture> loadTexture(const std::string &path);

	/**
	 * Creates/saves a font that can be reused by our game.
	 */
	std::shared_ptr<TTF_Font> loadFont(const std::string &path);

	/**
	 * Loads a level.
	 */
	void loadLevel(Platformance *level, unsigned int newLevel);

	/**
	 * Creates/saves a sound that can be reused by our game.
	 */
	std::shared_ptr<Mix_Chunk> loadSound(const std::string &path);

	/**
	 * Creates/saves music that can be reused by our game.
	 */
	std::shared_ptr<Mix_Music> loadMusic(const std::string &path);

	/**
	 * Loads a specific locale and returns the string mapping vector
	 */
	std::vector<std::string> loadLocale(std::string path);
};
