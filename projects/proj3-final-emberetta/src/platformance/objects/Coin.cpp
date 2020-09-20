/*
 * Coin.cpp
 *
 *  Created on: Feb 22, 2020
 *  Author: 
 */

#include "platformance/objects/Coin.hpp"
#include "platformance/ObjectTypes.hpp"
#include "base/RectRenderComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/TextureRenderComponent.hpp"

Coin::Coin(float x, float y, float w, float h): GameObject(x, y, w, h, PlatformanceObjects::TAG_COIN) {
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	SDL_Rect src{0, 0, 563, 564};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "Gold_1.png", src));
}

std::ostream& Coin::print(std::ostream &out) {
	return out << PlatformanceObjects::TAG_COIN << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}
