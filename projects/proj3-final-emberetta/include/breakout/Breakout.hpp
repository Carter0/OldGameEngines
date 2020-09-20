#pragma once

#include "base/Level.hpp"
#include "managers/InputManager.hpp"
#include <iostream>

const int MAX_LEVELS_BREAKOUT = 3;
const std::string BREAKOUT_RESAFFIX = "breakout/";

//! \brief A class representing one instance of the game of breakout.
class Breakout: public Level {
public:
	Breakout(int w, int h);
	virtual ~Breakout() { };
	virtual void update() override;
	virtual void render(SDL_Renderer *renderer) override;
	/**
	 * Clears all current gameobjects from the game
	 */
	void clear();
	virtual void loadLevel(int level = 1) override;
	void alterValues(float &x, float &y, float &w, float &h);
	//void renderEditor(SDL_Renderer* renderer);

	int balls = 1;

protected:
	bool m_stopped {false};


};
