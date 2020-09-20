#include "base/PhysicsComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include "platformance/ObjectTypes.hpp"
#include <cmath>

//! \brief A component which will add a GameObject to the physics engine.
PhysicsComponent::PhysicsComponent(GameObject &gameObject, bool solid) :
		Component(gameObject), mSolid(solid), mVx(0.0f), mVy(0.0f) {
}

void PhysicsComponent::step(Level &level) {
	gameObject().setX(gameObject().x() + mVx);
	gameObject().setY(gameObject().y() + mVy);

	if (!mSolid) {
		std::vector < std::shared_ptr < GameObject >> objects;
		if (level.getCollisions(gameObject(), objects)) {
			for (auto obj : objects) {
				if (obj->tag() == TAG_BLOCK) {
					if (hitRight(obj->x(), obj->y(), obj->w(), obj->h())) { //going right
						gameObject().setX(obj->x() - gameObject().w());
						mVx = 0;
					}

					if (hitLeft(obj->x(), obj->y(), obj->w(), obj->h())) { //going left
						gameObject().setX(obj->x() + obj->w());
						mVx = 0;
					}

					if (hitFloor(obj->x(), obj->y(), obj->w(), obj->h())) { //falling onto a floor
						gameObject().setY(obj->y() - gameObject().h());
						mVy = 0;
					}

					if (hitCeiling(obj->x(), obj->y(), obj->w(), obj->h())) { //hitting a ceiling
						gameObject().setY(obj->y() + obj->h());
						mVy = 0;
					}
				} else {
					gameObject().collision(level, obj);
				}
			}
		}
	}
}

bool PhysicsComponent::hitFloor(float x, float y, float w, float h) {
	return mVy > 0 //while falling
	&& gameObject().y() + gameObject().h() >= y//and the player's bottom is lower than the object's top
	&& (gameObject().y() < y);//and the player's top is higher than the object's top,
}

bool PhysicsComponent::hitCeiling(float x, float y, float w, float h) {
	return mVy < 0 //while rising
	&& gameObject().y() <= y + h//and the player's top is higher than the object's bottom
	&& gameObject().y() + gameObject().h() >= y + h;//and the player's bottom is lower than the object's bottom
}

bool PhysicsComponent::hitRight(float x, float y, float w, float h) {
	return mVx > 0 //while moving right
	&& gameObject().x() + gameObject().w() > x//and the player's right is more rightward than the object's left
	&& gameObject().x() < x//and the player's left is more leftward than the object's left
	&& std::abs(gameObject().y() + gameObject().h() - y) > 3;
}

bool PhysicsComponent::hitLeft(float x, float y, float w, float h) {
	return mVx < 0 //while moving left
	&& gameObject().x() < x + w//and the player's left is more leftward than the object's right
	&& gameObject().x() + gameObject().w() > x + w//and the player's right is more rightward than the object's right
	&& std::abs(gameObject().y() + gameObject().h() - y) > 3;
}
