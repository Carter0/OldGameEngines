/*
 * PowerUpComponent.hpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_COMPONENTS_POWERUPCOMPONENT_HPP_
#define INCLUDE_EMBERETTA_COMPONENTS_POWERUPCOMPONENT_HPP_

#include "emberetta/ObjectTypes.hpp"
#include "base/GenericComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include "emberetta/objects/PowerUp.hpp"


class PowerUpComponent : public GenericComponent {

public:
	PowerUpComponent(GameObject & gameObject, int type, int tag);
	virtual void collision(Level & level, std::shared_ptr<GameObject> obj) override;
private:
	int m_type {0};
	int m_tag;
};

#endif /* INCLUDE_EMBERETTA_COMPONENTS_POWERUPCOMPONENT_HPP_ */
