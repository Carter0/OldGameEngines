/*
 * PowerUpComponent.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */

#include "emberetta/components/PowerUpComponent.hpp"
#include "emberetta/objects/PlayerWeaponsFactory.hpp"

PowerUpComponent::PowerUpComponent(GameObject & gameObject, int type, int tag): GenericComponent(gameObject), m_type(type),m_tag(tag) {

}

void PowerUpComponent::collision(Level & level, std::shared_ptr<GameObject> obj) {
	  if (obj->tag() == m_tag) {
		  if (m_type != 3) {
			  PlayerWeaponsFactory::getInstance().setType(m_type);
		  } else {
			  level.addLife();
		  }
	  }
}
