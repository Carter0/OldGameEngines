/*
 * Ball.hpp
 *
 *  Created on: Feb 2, 2020
 *  Author: Nicolas Karayakaylar
 */

#pragma once
#ifndef BALL_HPP_
#define BALL_HPP_

#include "GameObject.hpp"
#include "Vector2D.hpp"
#include <SDL.h>
#include <math.h>

/**
 * A class to represent a Ball in the game of Breakout. Tracks and updates the ball's position
 * and handles a significant amount of the game's collision.
 */
class Ball : public GameObject {
public:
	/**
	 * Simple, default constructor, leaving the ball at its default speed, position, and direction.
	 */
	Ball();

	/**
	 * Creates another ball at the same position as the base, but at a different angle
	 * @return new ball with different trajectory than the original
	 */
	Ball split();

	/**
	 * Provides a BoundingBox which represents the Ball's current position, for use with collision math.
	 * @return a BoundingBox representing this Ball's current position
	 */
	BoundingBox getPosition();

	/**
	 * Provides a Cector2D which represents the Ball's current position, for use with collision math.
	 * @return a Vector2D representing this Ball's current direction
	 */
	Vector2D getDirection();


	/**
	 * Draws the ball on the screen.
	 * @param render Takes in an SDL renderer, which will be used to render this Ball.
	 */
	void render(SDL_Renderer * render);

	/**
	 * Updates the Ball's current position, called on every frame as the game runs.
	 */
	void update();

	/**
	 * Checks to see if the ball is offscreen
	 * @return true if offscrean
	 */
	bool isballOffScreen();

	/**
	 * Bounces the ball based on the brick it hit.
	 * @param brickBox BoundingBox representing the brick
	 */
	void bounce(BoundingBox brickBox);

	/**
	 * Bounces the ball based on the paddle it hit.
	 * @param brickBox BoundingBox representing the paddle
	 */
	void paddleBounce(BoundingBox brickBox);

	/**
	 * Checks to see if the ball has collided with another object
	 * @param other the BoundingBox of the other GameObject
	 * @return true if collided
	 */
	bool collided(BoundingBox other);

	/**
	 * Returns the radius of the Ball
	 * @return the radius
	 */
	int getRadius();

	/**
	 * sets the ball's position, direction, and speed back to the default.
	 */
	void reset();
	/**
	 * Returns the speed of the Ball
	 * @return the speed
	 */
	int getSpeed() { return speed; }
	/**
	 * Sets the speed of the Ball
	 * @param newSpeed The new Speed of the ball
	 */
	void setSpeed(int newSpeed) { speed = newSpeed; }

private:
	Vector2D direction, position;
	int speed, radius;
};

#endif
