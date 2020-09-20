/*
 * Platformance.hpp
 *
 *  Created on: Mar 9, 2020
 *      Author: jaked
 */

#pragma once

#include "base/Level.hpp"
#include "managers/InputManager.hpp"
#include "Platformance.hpp"
#include "platformance/ObjectTypes.hpp"
#include <iostream>

//! \brief A class representing one instance of the game's level editor.
class PlatformanceEditor: public Platformance {
public:
	PlatformanceEditor(int w, int h);
	virtual ~PlatformanceEditor() { };
	virtual void update();
	virtual void render(SDL_Renderer *renderer);
	void clear();
	virtual void loadLevel(int level = 1);
	void alterValues(float &x, float &y, float &w, float &h);
	//void renderEditor(SDL_Renderer* renderer);

private:

	const static int PLACING_COIN = 5;
	const static int PLACING_PLAYER = 6;
	const static int PLACING_BLOCK = 7;
	const static int PLACING_GOAL = 8;
	const static int PLACING_ENEMY = 9;
	int placing = PLACING_BLOCK;
	bool blocking = false;
	Vector2D blockCorner = Vector2D(0, 0);
	Vector2D endCorner = Vector2D(0, 0);
};
