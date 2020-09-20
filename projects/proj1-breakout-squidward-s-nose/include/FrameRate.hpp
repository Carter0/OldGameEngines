/*
 * FrameRate.hpp
 *
 *  Created on: Jan 17, 2020
 *      Author: Jake Dec
 */
#pragma once
#ifndef INCLUDE_FRAMERATE_HPP_
#define INCLUDE_FRAMERATE_HPP_

#include <deque>
#include <stdint.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "ResourceManager.hpp"
#include "Util.hpp"

/**
 * A class to visually represent and manage the frame rate of the game Breakout.
 */

class FrameRate {

public:
	const uint32_t frameCounts = 60;
	const uint32_t frameRateLimit = 60;

	FrameRate(const std::string& path);
	~FrameRate();

	/**
	 * Adds the absolute tick number to the game's rolling frame rate.
	 */
	void addTime();


	/**
	 * Provides the number of ticks that have passed since the addTime() method was last called.
	 *
	 * @return an integer number of ticks
	 */
	int sinceLast();

	/**
	 * Updates the current framerate, displaying the most accurate number, and scaling appropriately to the screen (if it has changed).
	 * Called once per frame.
	 *
	 * @param screenWidth The current screen width
	 * @param screenHeight The current screen height
	 * @param ren The renderer which will be used to render this Framerate
	 */
	void update(int screenWidth, int screenHeight, std::shared_ptr<SDL_Renderer> ren);

	/**
	 * Draws the framerate
	 * @param ren Renderer to draw with
	 */
	void render(std::shared_ptr<SDL_Renderer> ren);

	/**
	 * Toggles framerate
	 */
	inline void toggle() { visible = !visible; }

private:
	SDL_Color color = {255,255,255,255};
	int x, y, h, w;
	std::shared_ptr<TTF_Font> font;
	std::shared_ptr<SDL_Texture> texture;
	Uint32 lastTick;
	std::deque<Uint32> times;
	// Returns the average time of the last X frames
	float averageTime();
	bool visible {false};
};



#endif /* INCLUDE_FRAMERATE_HPP_ */
