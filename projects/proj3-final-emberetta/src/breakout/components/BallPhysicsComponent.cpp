#include "breakout/components/BallPhysicsComponent.hpp"

#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include <iostream>

//! \brief A component which will add the ball gameobject to physics.
BallPhysicsComponent::BallPhysicsComponent(GameObject &gameObject, bool solid, float xSpeed, float ySpeed) :
	PhysicsComponent(gameObject, solid) 
{
    setVx(xSpeed); 
    setVy(ySpeed); 
}

void BallPhysicsComponent::step(Level &level) {
	gameObject().setX(gameObject().x() + vx());
	gameObject().setY(gameObject().y() + vy());

	if (!isSolid()) {
		std::vector < std::shared_ptr < GameObject >> objects;
		if (level.getCollisions(gameObject(), objects)) {
			for (auto obj : objects) {
				if (obj->physicsComponent()->isSolid()) {
					if (obj->typeCheck() == "Paddle") {
						float xoffset = gameObject().x() + gameObject().w() / 2 - (obj->x() + obj->w() / 2);//bounces off the paddle on the side it hit
						setVx(xoffset / sqrt(abs(xoffset)));
						setVy(-1 * vy());
					} else {
						if (hitRight(obj->x(), obj->y(), obj->w(), obj->h())) { //going right
							gameObject().setX(obj->x() - gameObject().w());
							setVx(-1 * vx());
						}
						if (hitLeft(obj->x(), obj->y(), obj->w(), obj->h())) { //going left
							gameObject().setX(obj->x() + obj->w());
							setVx(-1 * vx());
						}
						if (hitFloor(obj->x(), obj->y(), obj->w(), obj->h())) { //falling onto a floor
							gameObject().setY(obj->y() - gameObject().h());
							setVy(-1 * vy());
						}
						if (hitCeiling(obj->x(), obj->y(), obj->w(), obj->h())) { //hitting a ceiling
							gameObject().setY(obj->y() + obj->h());
							setVy(-1 * vy());
						}
					}
				}
				gameObject().collision(level, obj);
			}
		}
	}
}
