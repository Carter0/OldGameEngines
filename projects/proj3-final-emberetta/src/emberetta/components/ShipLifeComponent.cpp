/*
 * ShipLifeComponent.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */

#include "emberetta/components/ShipLifeComponent.hpp"

ShipLifeComponent::ShipLifeComponent(GameObject & gameObject, EnemyShip* this_ptr, int tag, unsigned int lives):
GenericComponent(gameObject),
m_this(this_ptr),
mTag(tag),
mLives(lives) {}

void ShipLifeComponent::collision(Level & level, std::shared_ptr<GameObject> obj) {
	if (obj->tag() == mTag) {
		mLives--;
		if (mLives <=0) {
			for (auto obj: level.objects()) {
				if (obj.get() == m_this) {
					level.removeObject(obj);
				}
			}
		}
	}
}


