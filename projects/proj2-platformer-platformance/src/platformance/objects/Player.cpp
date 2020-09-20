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
#include "platformance/components/StayInWorldComponent.hpp"
#include "base/PlayerRenderComponent.hpp"
#include "base/AddPointsOnCollisionComponent.hpp"


Player::Player(float x, float y, float w, float h): GameObject(x, y, w, h, TAG_PLAYER) {
	addGenericCompenent(std::make_shared<AddPointsOnCollisionComponent>(*this, TAG_COIN));
	addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_COIN));
	addGenericCompenent(std::make_shared<SoundOnCollideComponent>(*this, TAG_COIN, "Blink.wav"));
	setRenderCompenent(std::make_shared<PlayerRenderComponent>(*this, "adventurer-Sheet.png"));
	addGenericCompenent(std::make_shared<InputComponent>(*this, 10.0f, 20.0f, 1.0f));
	addGenericCompenent(std::make_shared<SoundOnCollideComponent>(*this, TAG_GOAL, "Blaster_long.wav"));
	addGenericCompenent(std::make_shared<CameraComponent>(*this));
	addGenericCompenent(std::make_shared<StayInWorldComponent>(*this));
	setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
	initX = x;
	initY = y;
}

//Player::~Player() {};

std::string Player::typeCheck() {
	return "Player";
}

std::ostream& Player::print(std::ostream &out) {
	return out << TAG_PLAYER << " " << initX << " " << initY << " " << this->w() << " " << this->h() << std::endl;
}
