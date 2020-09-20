/*
 * ShipInputComponent.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#include "emberetta/components/ShipInputComponent.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "managers/InputManager.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"

ShipInputComponent::ShipInputComponent(PlayerShip & gameObject, float thrusterSpeed, float baseForwardVelocity):
	GenericComponent(gameObject),
	m_speed(thrusterSpeed),
	m_baseForwardVelocity(baseForwardVelocity),
	m_ship(gameObject){
	  (void) m_ship; // to prevent warnings
}


void ShipInputComponent::update(Level & level)
{
	bool left = InputManager::getInstance().isKeyDown(SDLK_LEFT) || InputManager::getInstance().isKeyDown(SDLK_a);
	bool right = InputManager::getInstance().isKeyDown(SDLK_RIGHT) || InputManager::getInstance().isKeyDown(SDLK_d);
	bool forward = InputManager::getInstance().isKeyDown(SDLK_UP) || InputManager::getInstance().isKeyDown(SDLK_w);
	bool reverse = InputManager::getInstance().isKeyDown(SDLK_DOWN) || InputManager::getInstance().isKeyDown(SDLK_s);
	bool space = InputManager::getInstance().isKeyDown(SDLK_SPACE);

	std::shared_ptr<PhysicsComponent> pc = gameObject().physicsComponent();

	if (left && !right) {
		pc->setVx(-m_speed);
	} else if (!left && right) {
		pc->setVx(m_speed);
	} else {
		pc->setVx(0.0f);
	}

	if (forward && !reverse) {
		pc->setVy(-m_speed - m_baseForwardVelocity);
	} else if (!forward && reverse) {
		pc->setVy(m_speed - m_baseForwardVelocity);
	} else {
		pc->setVy(- m_baseForwardVelocity);
	}

	if (space) {
		std::vector<std::shared_ptr<GameObject>> bullets = m_ship.fireWeapon();
		for (auto bullet : bullets) {
			level.addObject(bullet);
		}
	}
}


