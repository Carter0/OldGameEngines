/*
 * CameraComponent.hpp
 *
 *  Created on: Mar 13, 2020
 *      Author: jaked
 */

#include "platformance/components/CameraComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include <iostream>


CameraComponent::CameraComponent(GameObject & gameObject):
GenericComponent(gameObject) {}


void CameraComponent::update(Level & level)
{

	Vector2D cameraOffset(gameObject().x() + gameObject().w()/2, gameObject().y() + gameObject().h()/2);

	// Bound the camera by the level
	cameraOffset.x = cameraOffset.x < level.w()/2 ? level.w()/2 : cameraOffset.x;
	cameraOffset.x = cameraOffset.x > level.getLevelSize().x - level.w()/2 ? level.getLevelSize().x - level.w()/2 : cameraOffset.x;
	cameraOffset.y = cameraOffset.y < level.h()/2 ? level.h()/2 : cameraOffset.y;
	cameraOffset.y = cameraOffset.y > level.getLevelSize().y - level.h()/2 ? level.getLevelSize().y - level.h()/2 : cameraOffset.y;

	cameraOffset.x -= level.w()/2;
	cameraOffset.y -= level.h()/2;
	GameObject::setCameraOffset(cameraOffset);
	//std::cout << level.getLevelSize().x << " " << level.getLevelSize().y << std::endl;
	//std::cout << cameraOffset.x << " " << cameraOffset.y << std::endl;
}
