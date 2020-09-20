/*
 * PowerUp.cpp
 *
 *  Created on: Feb 18, 2020
 *      Author: Jake Dec
 */

#include "PowerUp.hpp"
#include "ResourceManager.hpp"
#include "AudioManager.hpp"
#include "Util.hpp"

PowerUp::PowerUp(int x, int y) {
	size.x = x;
	size.y = y;
	type = static_cast<PowerUpType>(rand() % TRIBALL + 1);
	texture = nullptr;
}

void PowerUp::update() {
	size.y += 1;
}

void PowerUp::render(SDL_Renderer * render) {
	if (!loaded) {
		texture = ResourceManager::getInstance().loadTexture(getTexturePath(type));
		loaded = true;
	}
	SDL_Rect dst;
	dst.x = size.x;
	dst.y = size.y;
	dst.w = size.w;
	dst.h = size.h;
	SDL_RenderCopy(render, texture.get(), NULL, &dst);
}

bool PowerUp::collision(PlayerPaddle& p) {
	// Do the two bounding boxes intersect?
    // If one rectangle is on left side of other
	BoundingBox paddle = p.getPosition();

	if (((size.y - size.h / 2 >= paddle.y && size.y - size.h / 2 <= paddle.y + paddle.h) ||//if the size's top point is between the brick's top and bottom points.
		(size.y + size.h / 2 >= paddle.y&& size.y + size.h / 2 <= paddle.y + paddle.h)) &&//if the size's bottom point is between the brick's top and bottom points.
		((size.x + size.w / 2 >= paddle.x && size.x + size.w / 2 <= paddle.x + paddle.w) ||//if the size's left point is between the brick's left and right points.
		(size.x - size.w / 2 >= paddle.x && size.x - size.w / 2 <= paddle.x + paddle.w))) {//if the size's right point is between the brick's left and right points
		consume();
		//AudioManager::getInstance().playSound(sound);
		return true;
	}
    return false;
}

void PowerUp::consume() {
	switch(type) {
	case SLOW:
		Breakout::getInstance().setBallSpeed(Breakout::getInstance().getBallSpeed() - 1);
		break;
	case FAST:
		Breakout::getInstance().setBallSpeed(Breakout::getInstance().getBallSpeed() + 2);
		break;
	case SHRINK:
		Breakout::getInstance().setPaddleWidth((int)(Breakout::getInstance().getPaddleWidth() * .8));
		break;
	case GROW:
		Breakout::getInstance().setPaddleWidth((int)(Breakout::getInstance().getPaddleWidth() * 1.2));
		break;
	case TRIBALL:
		Breakout::getInstance().triball();
		break;
	case LIFE:
		Breakout::getInstance().addLife();
		break;
	default:
		break;
	}
	consumed = true;
//	std::cout << "Here3" << std::endl;

}

std::string PowerUp::getTexturePath(PowerUpType type) {
	switch(type) {
	case SLOW: return "slowball.png";
	case FAST: return "fastball.png";
	case SHRINK: return "shrink.png";
	case GROW: return "expand.png";
	case TRIBALL: return "triball.png";
	case LIFE:
		size.w = 30;
		size.h = 30;
		return "heart.png";
	}
	return "";
}
