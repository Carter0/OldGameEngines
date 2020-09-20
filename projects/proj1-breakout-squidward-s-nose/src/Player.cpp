/*
 * Player.cpp
 *
 *  Created on: Feb 2, 2020
 *  Author: Carter Weinberg
 */

#include "Player.hpp"

PlayerPaddle::PlayerPaddle() {
    // Half X, a little below the ball for the Y.
    parameters = BoundingBox(640, 600, 200, 40);
    // Set the starting lives equal to 3 for now.
    lives = 3;
    // Set the player velocity to 0 on start
    velocity = 0;
    speed = 10;
}

void PlayerPaddle::loseLife() {
    lives -= 1;
}

const int PlayerPaddle::getLives() {
    return lives;
}

void PlayerPaddle::update() {
    parameters.x += velocity * speed;
}

void PlayerPaddle::render(SDL_Renderer * renderer){
    SDL_Rect playerRect = {parameters.x, parameters.y, parameters.w, parameters.h};
    SDL_SetRenderDrawColor(renderer, 98, 82, 158, 0xFF);
    SDL_RenderFillRect(renderer, &playerRect);
}

void PlayerPaddle::setVelocity(const int newVelocity, const bool isRight) {
    if (isRight) {
        velocity = newVelocity * -1;
    }
    else if (!isRight) {
        velocity = newVelocity * -1;
    }
}

BoundingBox PlayerPaddle::getPosition() {
    return parameters;
}

bool PlayerPaddle::collision(Ball& b) {
	// Do the two bounding boxes intersect?
    // If one rectangle is on left side of other
	BoundingBox ball = b.getPosition();

    //We intersect in the X axis
	if (b.getDirection().Y() > 0 &&//Ball is moving downwards
		((ball.y - ball.h / 2 >= parameters.y && ball.y - ball.h / 2 <= parameters.y + parameters.h) ||//if the ball's top point is between the paddle's top and bottom points.
		(ball.y + ball.h / 2 >= parameters.y&& ball.y + ball.h / 2 <= parameters.y + parameters.h)) &&//if the ball's bottom point is between the paddle's top and bottom points.
		((ball.x + ball.w / 2 >= parameters.x && ball.x + ball.w / 2 <= parameters.x + parameters.w) ||//if the ball's left point is between the paddle's left and right points.
		(ball.x - ball.w / 2 >= parameters.x && ball.x - ball.w / 2 <= parameters.x + parameters.w))) {//if the ball's right point is between the paddle's left and right points
		b.paddleBounce(parameters);
		AudioManager::getInstance().playSound(sound);
		return true;
	}
    return false;
}
