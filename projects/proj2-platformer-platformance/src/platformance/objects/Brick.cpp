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

//class TextureRenderComponent;

Brick::Brick(float x, float y, float w, float h): GameObject(x, y, w, h, TAG_BLOCK) {
	setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, true));
	SDL_Rect src{0, 0, 32, 32};
	setRenderCompenent(std::make_shared<TextureRenderComponent>(*this, "brick.png", src));
}

std::ostream& Brick::print(std::ostream &out) {
	return out << TAG_BLOCK << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}

//Brick::~Brick(){};
