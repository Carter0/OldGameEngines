#include "base/StayInWorldComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"

/*
 * StayInWroldComponent.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

StayInWorldComponent::StayInWorldComponent(GameObject & gameObject) : GenericComponent(gameObject) {}

void StayInWorldComponent::update(Level & level) {
	int objX = gameObject().x();
	int objY = gameObject().y();
	objX = objX < 0 ? 0 : objX;
	objX = objX + gameObject().w() > level.getLevelSize().x ? level.getLevelSize().x - gameObject().w() : objX;
	objY = objY + gameObject().h() > level.getLevelSize().y ? level.getLevelSize().y - gameObject().h() : objY;
	gameObject().setX(objX);
	gameObject().setY(objY);
}

