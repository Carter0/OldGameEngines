/*
 * InputComponent.hpp
 *
 *  Created on: Mar 9, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_PLATFORMACE_INPUTCOMPONENT_HPP_
#define INCLUDE_PLATFORMACE_INPUTCOMPONENT_HPP_

#include "base/GenericComponent.hpp"

//! \brief Component for handling (keyboard) input
class InputComponent: public GenericComponent {
public:
	InputComponent(GameObject & gameObject, float speed, float jump, float gravity);

	/**
	 * Checks for input and updates the player position, as well as applies gravity to the
	 * player, if needed
	 */
	virtual void update(Level & level) override;

private:

	float mSpeed;
	float mJump;
	float mGravity;
};

#endif /* INCLUDE_PLATFORMACE_INPUTCOMPONENT_HPP_ */
