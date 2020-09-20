/*
 * CameraComponent.hpp
 *
 *  Created on: Mar 13, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_PLATFORMANCE_COMPONENTS_CAMERACOMPONENT_HPP_
#define INCLUDE_PLATFORMANCE_COMPONENTS_CAMERACOMPONENT_HPP_


#include "base/GenericComponent.hpp"
#include "TinyMath.hpp"

//! \brief Class for representing a Camera component
class CameraComponent: public GenericComponent {
public:
	CameraComponent(GameObject & gameObject);

	/**
	 * Set the camera focused on the player
	 */
	virtual void update(Level & level) override;
};

#endif /* INCLUDE_PLATFORMANCE_COMPONENTS_CAMERACOMPONENT_HPP_ */
