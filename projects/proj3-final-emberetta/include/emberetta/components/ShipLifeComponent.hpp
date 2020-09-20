/*
 * ShipLifeComponent.hpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_COMPONENTS_SHIPLIFECOMPONENT_HPP_
#define INCLUDE_EMBERETTA_COMPONENTS_SHIPLIFECOMPONENT_HPP_

#include "emberetta/ObjectTypes.hpp"
#include "base/GenericComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include "emberetta/objects/EnemyShip.hpp"

//! \brief A component that removes the enemy gameobject when they run out of lives.
class ShipLifeComponent: public GenericComponent {
public:

	ShipLifeComponent(GameObject & gameObject, EnemyShip* this_ptr, int tag, unsigned int lives);

	virtual void collision(Level & level, std::shared_ptr<GameObject> obj) override;

private:

	EnemyShip* m_this;
	int mTag;
	unsigned int mLives;

};



#endif /* INCLUDE_EMBERETTA_COMPONENTS_SHIPLIFECOMPONENT_HPP_ */
