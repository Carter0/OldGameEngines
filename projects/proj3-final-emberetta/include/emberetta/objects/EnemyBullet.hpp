/*
 * EnemyBullet.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTS_ENEMYBULLET_HPP_
#define INCLUDE_EMBERETTA_OBJECTS_ENEMYBULLET_HPP_

#include "base/GameObject.hpp"
#include "Util.hpp"
#include "platformance/ObjectTypes.hpp"



/**
 * Base Class for all player weapons
 * Creates an enemy bullet that damages the playe
 * Intended to be overwritten with weapon specfic logic, just a rectangle for now
 */
class EnemyBullet : public GameObject {
public:
	/**
	 * Starting Position of the bullet.
	 */
	EnemyBullet(float x, float y, float speedX, float speedY);
	EnemyBullet(float x, float y, float speedX, float speedY, int tag);

	std::ostream& print(std::ostream &out) override;

};

class EnemyPellet : public EnemyBullet {
public:
	/**
	 * Starting Position of the bullet.
	 */
	EnemyPellet(float x, float y, float speedX, float speedY);

};

class EnemyBomb : public EnemyBullet {
public:
	/**
	 * Starting Position of the bullet.
	 */
	EnemyBomb(float x, float y, float speedX, float speedY);

};

class BombDeleter : public GameObject {
public:
	BombDeleter(float x, float y, float speedX, float speedY);
};


#endif /* INCLUDE_EMBERETTA_OBJECTS_ENEMYBULLET_HPP_ */
