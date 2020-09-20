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

#include "Util.hpp"

#include "breakout/Breakout.hpp"
#include "breakout/objects/Wall.hpp"
#include "breakout/objects/Score.hpp"
#include "breakout/objects/Lives.hpp"
#include "breakout/objects/Ball.hpp"
#include "breakout/objects/Block.hpp"
#include "breakout/objects/Paddle.hpp"

#include "platformance/Platformance.hpp"
#include "platformance/objects/Enemy.hpp"
#include "platformance/objects/Goal.hpp"
#include "platformance/objects/GameController.hpp"

#include "emberetta/Emberetta.hpp"
#include "emberetta/objects/PlayerShip.hpp"
#include "emberetta/objects/Score.hpp"
#include "emberetta/objects/Lives.hpp"
#include "emberetta/objects/Spawner.hpp"

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

	std::string m_resAffix;
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
	 * @param resPrefix fold in which game assets are stored under res directory
	 * @param rend render to be used for game
	 */
	int startUp(std::string resAffix, std::shared_ptr<SDL_Renderer> rend);

	/**
	 * Equivalent to a constructor.
	 * @param rend render to be used for game
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
	 * Loads a level of platformance.
	 */
	void loadLevel(Platformance *level, unsigned int newLevel);

	/**
	 * Loads a level of breakout.
	 */
	void loadLevel(Breakout *level, unsigned int newLevel);

	/**
	 * Loads a level of emberetta.
	 */
	void loadLevel(Emberetta *level, unsigned int newLevel);

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
