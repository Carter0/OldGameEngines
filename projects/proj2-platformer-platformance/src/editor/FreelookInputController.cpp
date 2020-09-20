/*
 * FreelookInputController.cpp
 *
 *  Created on: Mar 21, 2020
 *      Author: jaked
 */


#include "editor/FreelookInputComponent.hpp"
#include "platformance/ObjectTypes.hpp"
#include "managers/InputManager.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"

FreelookInputComponent::FreelookInputComponent(GameObject & gameObject, float speed):
	GenericComponent(gameObject),
	mSpeed(speed){}


void FreelookInputComponent::update(Level & level)
{
	bool left = InputManager::getInstance().isKeyDown(SDLK_LEFT);
	bool right = InputManager::getInstance().isKeyDown(SDLK_RIGHT);
	bool up = InputManager::getInstance().isKeyPressed(SDLK_UP);
	bool down = InputManager::getInstance().isKeyPressed(SDLK_UP);

	std::shared_ptr<PhysicsComponent> pc = gameObject().physicsComponent();

	if (left && !right) {
		pc->setVx(-mSpeed);
	} else if (!left && right) {
		pc->setVx(mSpeed);
	} else {
		pc->setVx(0.0f);
	}

	if (up && !down) {
		pc->setVy(-mSpeed);
	} else if (!up && down) {
		pc->setVy(mSpeed);
	} else {
		pc->setVy(0.0f);
	}


}



