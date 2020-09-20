/*
 * EmberettaCamera.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#include "emberetta/ObjectTypes.hpp"
#include "emberetta/components/EmberettaCamera.hpp"

using namespace EmberettaObjects;

EmberettaCamera::EmberettaCamera(GameObject & gameObject) : GenericComponent(gameObject) {}
void EmberettaCamera::update(Level & level) {
	for (auto obj: level.objects()){
		// If the object is outside the level, remove it
		if (obj->tag() < 90 && obj->tag() > 5) {
			if (obj->x() + obj->w() < 0 ||
					obj->x() > level.getLevelSize().x ||
					obj->y() > level.getLevelSize().y ||
					obj->y() < -200) {
				level.removeObjectSilent(obj);
			}
		}
		if (obj->tag() == TAG_BACKGROUND) {
			if (obj->y() > level.getLevelSize().y) {
				obj->setY(0);
			}
		}
	}
}



