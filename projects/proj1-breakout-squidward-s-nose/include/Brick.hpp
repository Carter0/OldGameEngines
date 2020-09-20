/*
 * Brick.h
 *
 *  Created on: Feb 4, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_BRICK_HPP_
#define INCLUDE_BRICK_HPP_

#include "GameObject.hpp"
#include "Ball.hpp"
#include "AudioManager.hpp"


/**
 * A class to represent a Brick in the game Breakout. It has a position, health, and handles collision as
 * well as sound.
 */
class Brick: public GameObject {
public:
	Brick(BoundingBox b, int health = 1);
	Brick(BoundingBox b, SDL_Color c, int health = 1);

	/**
	 * Checks whether this Brick has been destroyed, and needs to be removed - called each frame.
	 */
	void update();

	/**
	* Draws the Brick on the screen.
	* @param render Takes in an SDL renderer, which will be used to render this Brick.
	*/
	void render(SDL_Renderer * renderer);

	/**
	 * Returns the BoundingBox for the brick
	 * @return BoundingBox of brick
	 */
	inline BoundingBox getPosition() { return size; };

	/**
	* Sets the size of the brick
	* @param b BoundingBox to represent the brick
	*/
	void setSize(BoundingBox b);

	/**
	* Sets the sound when brick is hit
	* @param path filename of sound
	*/
	void setSound(const std::string & path);

	/**
	 * Checks whether this Brick has collided with the Ball.
	 * @param b the Ball which may or may not have collided with this Brick
	 * @return a bool describing whether the collision has occurred.
	 */
	bool collision(Ball& b);

	/**
	 * @return true if brick health is 0
	 */
	inline bool isDestroyed() { return health == 0; };

private:
	// Default is a non-existent blue brick with one life, at the top left of the screen
	BoundingBox size {0,0,0,0};
	SDL_Color color {0,0,255,255};
	std::string sound {"block.wav"};
	int health {1};

};

#endif /* INCLUDE_BRICK_HPP_ */
