/*
 * Brick.cpp
 *
 *  Created on: Feb 22, 2020
 *  Author: 
 */

#include "platformance/objects/Brick.hpp"
#include "platformance/ObjectTypes.hpp"
#include "base/GameObject.hpp"
#include "base/TextureRenderComponent.hpp"
#include "base/PhysicsComponent.hpp"

Brick::Brick(float x, float y, float w, float h): GameObject(x, y, w, h, PlatformanceObjects::TAG_BRICK) {
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, true));

	SDL_Rect src{0, 0, 32, 32};
	setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "brick.png", src));
}

std::ostream& Brick::print(std::ostream &out) {
	return out << PlatformanceObjects::TAG_BRICK << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}


//Brick::~Brick(){};
