/*
 * StayInCameraFrameComponent.hpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_PLATFORMANCE_COMPONENTS_STAYINWORLDCOMPONENT_HPP_
#define INCLUDE_PLATFORMANCE_COMPONENTS_STAYINWORLDCOMPONENT_HPP_

#include "base/GenericComponent.hpp"

//! \brief Component for handling collision and preventing the player from going out-of-bounds.
class StayInWorldComponent: public GenericComponent {
public:
	StayInWorldComponent(GameObject & gameObject);
	/**
	 * Prevents the GameObject from leaving the bounds of the world.
	 */
	virtual void update(Level & level) override;
};



#endif /* INCLUDE_PLATFORMANCE_COMPONENTS_STAYINWORLDCOMPONENT_HPP_ */
