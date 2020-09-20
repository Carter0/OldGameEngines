#pragma once
#ifndef INCLUDE_BREAKOUT_INPUTCOMPONENT_HPP_
#define INCLUDE_BREAKOUT_INPUTCOMPONENT_HPP_

#include "base/GenericComponent.hpp"

//! \brief Component for handling paddle (keyboard) input
class PaddleInputComponent: public GenericComponent {
public:
	PaddleInputComponent(GameObject & gameObject, float speed);

	/**
     * Moves the paddle a certain amount depending on the input
	 */
	virtual void update(Level & level) override;

private:

	float mSpeed;
};

#endif