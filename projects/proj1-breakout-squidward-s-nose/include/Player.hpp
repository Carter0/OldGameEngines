/*
 * Player.hpp
 *
 *  Created on: Feb 2, 2020
 *  Author: Carter Weinberg
 */

#pragma once
#ifndef PLAYER_PADDLE_HPP_
#define PLAYER_PADDLE_HPP_


#include "GameObject.hpp"
#include "Ball.hpp"
#include "AudioManager.hpp"

class PlayerPaddle : public GameObject {
public:

    PlayerPaddle();

    /**
    * The balls positions will always be moving by the velocity.
    * But, the velocity will change on keypress.
    */
    void update();

    /**
     * Draws this PlayerPaddle on the screen.
     *
     * @param renderer A renderer which is used to draw this PlayerPaddle
     */
	void render(SDL_Renderer * renderer);

    /**
    * Set the velocity when the key is down to whatever speed.
    * Reset the velocity on keyup to 0.
    */
    void setVelocity(const int newVelocity, const bool isRight);

    void loseLife();

    const int getLives();
    void setLives(int count) { lives = count; }

    BoundingBox getPosition();
    void setWidth(int width) { parameters.w = width; };

    bool collision(Ball& b);

private:
    BoundingBox parameters;
    int lives;

    // Velocity is either 1, -1, 0
    int velocity;
    // Speed refers to how fast the player shoud move
    int speed;
	std::string sound {"paddle.wav"};
};

#endif
