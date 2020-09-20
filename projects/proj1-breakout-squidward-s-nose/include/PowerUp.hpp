/*
 * PowerUp.hpp
 *
 *  Created on: Feb 18, 2020
 *      Author: Jake Dec
 */

#ifndef INCLUDE_POWERUP_HPP_
#define INCLUDE_POWERUP_HPP_

#include "GameObject.hpp"
#include "Breakout.hpp"

// Forward declaring this so that the shared_ptr doesn't freak out.
class Breakout;

enum PowerUpType { SHRINK, GROW, SLOW, FAST, LIFE, TRIBALL };

class PowerUp : public GameObject {

public:
	/**
	 * Constructs a random powerup.
	 */
	PowerUp(int x , int y);
	~PowerUp(){};
	/**
	 * Updates the gameobject for the next frame.
	 */
	void update();

	/**
	 * Render the gameobject.
	 */
	void render(SDL_Renderer * render);

	/**
	 * Consume the powerup.
	 */
	void consume();

	inline BoundingBox getPosition() { return size; }
	std::string getTexturePath(PowerUpType type);

	bool isOffScreen() { return size.y > 720; }
	bool isConsumed() { return consumed; }

	bool collision(PlayerPaddle& p);

private:
	PowerUpType type;
	std::shared_ptr<SDL_Texture> texture;
	BoundingBox size {0,0,60,30};
	std::shared_ptr<Breakout> game;
	bool consumed { false };
	bool loaded { false };

};



#endif /* INCLUDE_POWERUP_HPP_ */
