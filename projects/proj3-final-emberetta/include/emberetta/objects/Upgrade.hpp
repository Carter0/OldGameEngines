/*
 * Upgrade.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTS_UPGRADE_HPP_
#define INCLUDE_EMBERETTA_OBJECTS_UPGRADE_HPP_

enum Upgrades { LASER, BULLET }

/**
 * Upgrade for the player ship
 */
Upgrade : public GameObject {
public:
	/**
	 * Starting Position of the Upgrade.
	 */
	Upgrade(float x, float y);

	//Needed a destructor so clang compiles.
	//virtual ~Player() = 0;

	std::ostream& print(std::ostream &out) override;

};



#endif /* INCLUDE_EMBERETTA_OBJECTS_UPGRADE_HPP_ */
