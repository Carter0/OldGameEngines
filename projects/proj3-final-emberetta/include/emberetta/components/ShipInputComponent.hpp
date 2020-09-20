/*
 * ShipInputComponent.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_COMPONENTS_SHIPINPUTCOMPONENT_HPP_
#define INCLUDE_EMBERETTA_COMPONENTS_SHIPINPUTCOMPONENT_HPP_

#include "base/GenericComponent.hpp"
#include "emberetta/objects/PlayerShip.hpp"

//! \brief Component for handling (keyboard) input in emberetta
class ShipInputComponent: public GenericComponent {
public:
	/**
	 *
	 */
	ShipInputComponent(PlayerShip & gameObject, float thrusterSpeed, float baseForwardVelocity);

	virtual void update(Level & level) override;

private:

	float m_speed;
	float m_baseForwardVelocity;
	PlayerShip & m_ship;
};



#endif /* INCLUDE_EMBERETTA_COMPONENTS_SHIPINPUTCOMPONENT_HPP_ */
