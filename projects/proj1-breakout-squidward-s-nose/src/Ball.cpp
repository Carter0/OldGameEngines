/*
 * Ball.hpp
 *
 *  Created on: Feb 2, 2020
 *  Author: Nicolas Karayakaylar
 */

#include "Ball.hpp"
#include <iostream>

Ball::Ball() {
	reset();
	radius = 10;//Temp values, we'll see what works.
}

void Ball::reset() {
	direction = Vector2D(1, -1);//Makes the ball's initial direction 45 degrees, which is customary for brickbreaking games.
	position = Vector2D(640, 540);//Halfway, width-wise, and three-quarters down, height-wise.
	speed = 5;//Temp values, we'll see what works.
}

void Ball::update() {
	position = Vector2D(position.X() + direction.X() * speed, position.Y() + direction.Y() * speed);
}

bool Ball::isballOffScreen() {
	return (position.Y() > 720 + radius) || (position.Y() < 0 - radius);
}

void Ball::render(SDL_Renderer * renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
	for (int i = 0; i < radius * 2; i++) {
		for (int j = 0; j < radius * 2; j++) {
			int dx = radius - i; // horizontal offset
			int dy = radius - j; // vertical offset
			if (dx * dx + dy * dy <= radius * radius) {
				SDL_RenderDrawPoint(renderer, position.X() + dx, position.Y() + dy);
			}
		}
	}
}

BoundingBox Ball::getPosition() {
	return BoundingBox(position.X(), position.Y(), radius * 2, radius * 2);
}

Vector2D Ball::getDirection() {
	return direction;
}

int Ball::getRadius() {
	return radius;
}

//Currently, bounce only bounces at a set 90-degree angle. It can easily be rewritten to have a wider angle variance.
void Ball::bounce(BoundingBox brickBox) {//This would also be a good position to increase the speed.
	if (position.Y() <= brickBox.y || position.Y() >= brickBox.y + brickBox.h) {//Hit was from below or above the brick
		direction = Vector2D(direction.X(), -direction.Y());
	} else {//Hit was on right or left of brick.
		direction = Vector2D(-direction.X(), direction.Y());
	}
}

void Ball::paddleBounce(BoundingBox brickBox) {
	float xoffset = position.X() - (brickBox.x + brickBox.w / 2.0f);//bounces off the paddle on the side it hit
	float yoffset = position.Y() - (brickBox.y + brickBox.h / 2.0f);
	float magnitude = sqrt(pow(xoffset, 2) + pow(yoffset, 2));
	direction = Vector2D(xoffset / magnitude, -1);//Does not lose any horizontal speed to avoid the "horizontal inchworm"
}

Ball Ball::split() {
	float value = (rand() % 11 + -5) * .5;

	float xVel = this->direction.X() * value;
	Ball newBall;
	newBall.position = this->position;
	newBall.speed = this->speed;
	newBall.radius = this->radius;
	float yVel = (rand() % 10 + 6) / 10.0;
	newBall.direction = Vector2D(xVel, this->direction.Y() * yVel);
	return newBall;
}
