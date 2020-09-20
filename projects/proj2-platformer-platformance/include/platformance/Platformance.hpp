/*
 * Platformance.hpp
 *
 *  Created on: Mar 9, 2020
 *      Author: jaked
 */

#pragma once

#include "base/Level.hpp"
#include "managers/InputManager.hpp"
#include <iostream>

const int MAX_LEVELS = 3;

//! \brief A class representing one instance of the game
class Platformance: public Level {
public:
	Platformance(int w, int h);
	virtual ~Platformance() { };
	virtual void update() override;
	virtual void render(SDL_Renderer *renderer) override;
	void clear();
	virtual void loadLevel(int level = 1) override;
	void alterValues(float &x, float &y, float &w, float &h);
	//void renderEditor(SDL_Renderer* renderer);

protected:
	bool m_stopped {false};

};
