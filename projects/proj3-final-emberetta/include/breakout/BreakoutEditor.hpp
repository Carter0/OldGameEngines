#pragma once

#include "base/Level.hpp"
#include "managers/InputManager.hpp"
#include "breakout/ObjectTypes.hpp"
#include "Breakout.hpp"
#include <iostream>

//! \brief A class representing one instance of the game of breakout.
class BreakoutEditor: public Breakout {
public:
	BreakoutEditor(int w, int h);
	virtual ~BreakoutEditor() { };
	virtual void update();
	virtual void render(SDL_Renderer *renderer);
	/**
	 * Clears all current gameobjects from the game
	 */
	void clear();
	virtual void loadLevel(int level = 1);
	void alterValues(float &x, float &y, float &w, float &h);
	//void renderEditor(SDL_Renderer* renderer);

protected:
	bool m_stopped {false};

public:
	int m_lives;

private:
	SDL_Renderer* mRenderer;
	const static int PLACING_BLOCK = 5;
	const static int PLACING_PADDLE = 6;
	const static int PLACING_BALL = 7;
	const static int PLACING_WALL = 8;
	int placing = PLACING_BLOCK;
	bool blocking = false;
	Vector2D blockCorner = Vector2D(0, 0);
	Vector2D endCorner = Vector2D(0, 0);
};
