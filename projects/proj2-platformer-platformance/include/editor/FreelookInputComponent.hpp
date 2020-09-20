/*
 * FreelookInputComponent.hpp
 *
 *  Created on: Mar 21, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EDITOR_FREELOOKINPUTCOMPONENT_HPP_
#define INCLUDE_EDITOR_FREELOOKINPUTCOMPONENT_HPP_

#include "base/GenericComponent.hpp"

class FreelookInputComponent: public GenericComponent {
public:
	FreelookInputComponent(GameObject & gameObject, float speed);

	/**
	 * Updates the GameObject with any input from the user
	 */
	virtual void update(Level & level) override;

private:
	float mSpeed;
};



#endif /* INCLUDE_EDITOR_FREELOOKINPUTCOMPONENT_HPP_ */
