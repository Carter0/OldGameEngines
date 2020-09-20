/*
 * GeneratePowerUpOnDestroy.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */
#include "emberetta/components/GeneratePowerUpOnDestroy.hpp"

GeneratePowerUpOnDestroy::GeneratePowerUpOnDestroy(GameObject & gameObject, float chance):
GenericComponent(gameObject),
m_chance(chance) {}

void GeneratePowerUpOnDestroy::onDestroy(Level & level) {
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if (r < m_chance) {
		level.addObject(std::make_shared<PowerUp>(gameObject().x(), gameObject().y()));
	}
}
