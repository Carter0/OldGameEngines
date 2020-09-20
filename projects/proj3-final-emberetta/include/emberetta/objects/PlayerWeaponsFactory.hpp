/*
 * PlayerWeaponsFactory.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTS_PLAYERWEAPONSFACTORY_HPP_
#define INCLUDE_EMBERETTA_OBJECTS_PLAYERWEAPONSFACTORY_HPP_

#include "base/GameObject.hpp"
#include "emberetta/ObjectTypes.hpp"
#include <vector>

/**
 * Keeps track of the current player weapons and creates the gameobjects related to them when needed in the game
 */
class PlayerWeaponsFactory {
public:

	inline void setType(int newType) {
		if (type == newType) {
			std::cout << "Upgrade" << std::endl;
			level = level >= 5 ? 5 : level + 1;
		}
		else {
			std::cout << "Set to " << newType << std::endl;
			type = newType;
			level = 1;
		}
	}

	static PlayerWeaponsFactory& getInstance()	{
		static PlayerWeaponsFactory inst;
		return inst;
	}

	/**
	 * Will reset the factory to the default values
	 */
	void reset() {
		level = 1;
		type = 0;
	}

	/**
	 * Fires the currently selected weapon from the given location, if the delay has been met.
	 */
	std::vector<std::shared_ptr<GameObject>> fireWeapon(float x,float y);

private:
	PlayerWeaponsFactory(){};
	~PlayerWeaponsFactory(){};
	PlayerWeaponsFactory(PlayerWeaponsFactory const&) = delete; // Avoid copy constructor.
	void operator=(PlayerWeaponsFactory const&) = delete; // Don't allow copy assignment.
	PlayerWeaponsFactory(PlayerWeaponsFactory const&&) = delete; // Avoid move constructor.
	void operator=(PlayerWeaponsFactory const&&) = delete; // Don't allow move assignment.

	int level {1};
	int type{0};
	Uint32 m_last;

};



#endif /* INCLUDE_EMBERETTA_OBJECTS_PLAYERWEAPONSFACTORY_HPP_ */
