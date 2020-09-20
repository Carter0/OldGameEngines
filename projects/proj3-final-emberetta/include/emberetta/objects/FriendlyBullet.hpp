/*
 * FriendlyBullet.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTS_FRIENDLYBULLET_HPP_
#define INCLUDE_EMBERETTA_OBJECTS_FRIENDLYBULLET_HPP_

#include "base/GameObject.hpp"
#include "Util.hpp"
#include "platformance/ObjectTypes.hpp"



/**
 * Base Class for all player weapons
 * Creates a friendly bullet that damages enemy units, but not the player (should they somehow hit themselves)
 * Intended to be overwritten with weapon specfic logic, just a rectangle for now
 */
class FriendlyBullet : public GameObject {
public:
	/**
	 * Starting Position of the bullet.
	 */
	FriendlyBullet(float x, float y, float speed);
	FriendlyBullet(float x, float y, float w, float h);

	std::ostream& print(std::ostream &out) override;

};

class FriendlyBulletTwo : public FriendlyBullet {
public:
	/**
	 * Starting Position of the bullet.
	 */
	FriendlyBulletTwo(float x, float y, float speedx, float speedy);

};

class FriendlyLaser : public FriendlyBullet {
public:
	/**
	 * Starting Position of the bullet.
	 */
	FriendlyLaser(float x, float y, float speedx, float speedy);

};


#endif /* INCLUDE_EMBERETTA_OBJECTS_FRIENDLYBULLET_HPP_ */
