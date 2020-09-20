/*
 * Breakout.hpp
 *
 *  Created on: Feb 2, 2020
 *  Author: Carter Weinberg
 */

#pragma once
#ifndef BREAKOUT_HPP_
#define BREAKOUT_HPP_

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <stdint.h>
#include <vector>

#include "Ball.hpp"
#include "Player.hpp"
#include "Brick.hpp"
#include "PowerUp.hpp"
#include "ResourceManager.hpp"
#include "AudioManager.hpp"
#include "Util.hpp"
#include "LocaleManager.hpp"
#include "StringMap.hpp"

class PowerUp;

#define MAXLEVEL 3

/**
* Breakout class will handle the gamelogic of the game. This allows us to keep the SDL2 functionality
* separate from the game functionality.
*/
class Breakout {
public:

    /**
    * Set the breakout font to use. 
    * @param resPath the font name
    */
    void setFont(const std::string& resPath);

    /**
    * Update will check for ball collisions in the game by going through every game object and 
    * checking to see if the ball has collided with it. 
    * This method will also update the positions of every gameobject in the game.
    *
    * If the players y position is greater than the height of the screen, 
    * then we lose a life as well. 
    */
    void update();

    /**
    * Render will render every gameobject by going through the list of gameobject and 
    * render each, one at a time.
    */
	void render(std::shared_ptr<SDL_Renderer>);

    /**
    * This will accept key up and down input and set the velocity of the player accordingly.
    * On keydown, it will increase the velocity. On Key up, it will reset the velocity to 0.
    */
    void keyInput(const std::string& direction, const bool isDown);

    /**
     * This is an assignment 1 function that creates the required breakout game.
     */
    void createBasicLevel(unsigned int level);

    /**
     * Returns an integer value based on the state of the current game
     * @return 0 if no end has been reached, returns 1 if you've won, and returns 2 if you've lost.
     */
    int getEndCondition();

    /**
     * Sets the next level of the game to load.
     * #param level the level to load
     */
    void setLevel(unsigned int level);

    /**
     * Returns the level of the game
	 * @return the current level of the game.
	 */
    unsigned int getLevel();
  
    /**
     * Starts the game of breakout
     */
    void start();

    /**
     * Returns the singleton instance of Breakout
     * @rteturn the Breakout game
     */
    static Breakout& getInstance()
	{
		static Breakout inst;
		return inst;
	}

    /**
     * Gets the current ball speed (all balls travel at the same speed)
     * @return speed of the ball
     */
    int getBallSpeed() { return balls[0].getSpeed(); }

    /**
     * Sets all the balls speeds to the given speed
     * @param newSpeed the new speed of the balls
     */
    void setBallSpeed(int newSpeed) { for (Ball & b: balls) b.setSpeed(newSpeed); }

    /**
     * Gets the current paddle width
     * @return paddle width
     */
    int getPaddleWidth() { return playerPaddle.getPosition().w; }

    /**
     * Sets the current paddle width
     * @param newWidth the new paddle width
     */
    void setPaddleWidth(int newWidth) { playerPaddle.setWidth(newWidth); }

    /**
     * Adds a life to the player.
     */
    void addLife() { playerPaddle.setLives(playerPaddle.getLives() + 1); }

    /**
     * Splits each existing ball into 3 balls with semi-random tragectories
     */
    void triball();


private:

	Breakout();  // Private Singleton
	~Breakout(){};
	Breakout(Breakout const&) = delete; // Avoid copy constructor.
	void operator=(Breakout const&) = delete; // Don't allow copy assignment.
	Breakout(Breakout const&&) = delete; // Avoid move constructor.
	void operator=(Breakout const&&) = delete; // Don't allow move assignment.

    // Boolean flags that determine if the player has won or lost the game.
    // Lose condition is player lives = 0, win condition is all bricks are destroyed.
    bool hasLost;
    bool hasWon;

    // The score for the game.
    unsigned int score {0};

    //the level the game is currently on.
    unsigned int level;

    // The font we are using to render the lives.
	std::shared_ptr<TTF_Font> font;

    // All the gameobjects we need for breakout.
    std::vector<Brick> bricks;
    std::vector<Brick> walls;
    std::vector<PowerUp> powerUps;
    std::vector<Ball> balls;
    PlayerPaddle playerPaddle; 
    std::string resPath {""};
    std::string music {"background.ogg"};

    // What is the chance to drop a power up (10% base)
    float powerUpChance { .20 };

    // For every brick hit, increase the chance until a powerup appears
    float powerUpBase {.20 };
    float powerUpIncrease {.05 };
};

#endif
