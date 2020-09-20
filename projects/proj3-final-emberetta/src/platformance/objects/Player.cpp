/*
 * Player.cpp
 *
 *  Created on: Feb 22, 2020
 *  Author: Carter Weinberg
 */

#include "platformance/objects/Player.hpp"
#include "platformance/components/InputComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/SoundOnCollideComponent.hpp"
#include "platformance/components/CameraComponent.hpp"
#include "base/StayInWorldComponent.hpp"
#include "base/PlayerRenderComponent.hpp"
#include "base/AddPointsOnCollisionComponent.hpp"


Player::Player(float x, float y, float w, float h): GameObject(x, y, w, h, PlatformanceObjects::TAG_PLAYER) {
	addGenericComponent(std::make_shared<AddPointsOnCollisionComponent>(*this, PlatformanceObjects::TAG_COIN, 10));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, PlatformanceObjects::TAG_COIN));
	addGenericComponent(std::make_shared<SoundOnCollideComponent>(*this, PlatformanceObjects::TAG_COIN, "Blink.wav"));
	setRenderComponent(std::make_shared<PlayerRenderComponent>(*this, "adventurer-Sheet.png"));
	addGenericComponent(std::make_shared<InputComponent>(*this, 10.0f, 20.0f, 1.0f));
	addGenericComponent(std::make_shared<SoundOnCollideComponent>(*this, PlatformanceObjects::TAG_GOAL, "Blaster_long.wav"));
	addGenericComponent(std::make_shared<CameraComponent>(*this));
	addGenericComponent(std::make_shared<StayInWorldComponent>(*this));
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));

	initX = x;
	initY = y;
}

std::string Player::typeCheck() {
	return "Player";
}

std::ostream& Player::print(std::ostream &out) {
	return out << PlatformanceObjects::TAG_PLAYER << " " << initX << " " << initY << " " << this->w() << " " << this->h() << std::endl;
}
