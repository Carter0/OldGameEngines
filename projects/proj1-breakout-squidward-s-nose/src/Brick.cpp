/*
 * Brick.cpp
 *
 *  Created on: Feb 4, 2020
 *      Author: jaked
 */

#include "Brick.hpp"

Brick::Brick(BoundingBox b, int h) {
	size = b;
	health = h;
}

Brick::Brick(BoundingBox b, SDL_Color c, int h) {
	color = c;
	size = b;
	health = h;
}

void Brick::setSize(BoundingBox b) {
	size = b;
}

void Brick::setSound(const std::string & path) {
	sound = path;
}

bool Brick::collision(Ball& b) {
	// Do the two bounding boxes intersect?
    // If one rectangle is on left side of other
	BoundingBox ball = b.getPosition();

	if (((ball.y - ball.h / 2 >= size.y && ball.y - ball.h / 2 <= size.y + size.h) ||//if the ball's top point is between the brick's top and bottom points.
		(ball.y + ball.h / 2 >= size.y&& ball.y + ball.h / 2 <= size.y + size.h)) &&//if the ball's bottom point is between the brick's top and bottom points.
		((ball.x + ball.w / 2 >= size.x && ball.x + ball.w / 2 <= size.x + size.w) ||//if the ball's left point is between the brick's left and right points.
		(ball.x - ball.w / 2 >= size.x && ball.x - ball.w / 2 <= size.x + size.w))) {//if the ball's right point is between the brick's left and right points
		b.bounce(size);
		AudioManager::getInstance().playSound(sound);
		health = (health > 0 ? health - 1: health);
		return true;
	}
    return false;
}

void Brick::update() {
	if (isDestroyed()) {
		return;
	}
	// Probably something health related here (color changing)
}

void Brick::render(SDL_Renderer * renderer) {
	if (isDestroyed()) {
		return;
	}
    SDL_Rect rect = {size.x, size.y, size.w, size.h};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
