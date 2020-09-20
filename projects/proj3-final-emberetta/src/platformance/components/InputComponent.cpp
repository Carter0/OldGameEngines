/*
 * InputComponent.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: jaked
 */

#include "platformance/components/InputComponent.hpp"
#include "platformance/ObjectTypes.hpp"
#include "managers/InputManager.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"

InputComponent::InputComponent(GameObject & gameObject, float speed, float jump, float gravity):
	GenericComponent(gameObject),
	mSpeed(speed),
	mJump(jump),
	mGravity(gravity){}


void InputComponent::update(Level & level)
{
	bool left = InputManager::getInstance().isKeyDown(SDLK_LEFT);
	bool right = InputManager::getInstance().isKeyDown(SDLK_RIGHT);
	bool jump = InputManager::getInstance().isKeyPressed(SDLK_UP);

	std::shared_ptr<PhysicsComponent> pc = gameObject().physicsComponent();

	if (left && !right) {
		pc->setVx(-mSpeed);
	} else if (!left && right) {
		pc->setVx(mSpeed);
	} else {
		pc->setVx(0.0f);
	}

	if (jump) {
		bool onGround = false;
		std::vector<std::shared_ptr<GameObject>> objects;
		if (level.getCollisions(gameObject().x(), gameObject().y() + gameObject().h() + 2.0f, objects)) {
			for (auto obj: objects) {

				if (obj->physicsComponent()->isSolid()) {
					onGround = true;
				}
			}
		}
		if (level.getCollisions(gameObject().x() + gameObject().w(), gameObject().y() + gameObject().h() + 2.0f, objects)) {
			for (auto obj: objects) {

				if (obj->physicsComponent()->isSolid()) {
					onGround = true;
				}
			}
		}
		if (onGround) {
			pc->setVy(-mJump);
			AudioManager::getInstance().playSound("jump_11.wav");
			return;
		}
	}

	pc->setVy(std::min(pc->vy() + mGravity, mJump));
}


