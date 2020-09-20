#ifndef PLAYER_SHIP_HPP_
#define PLAYER_SHIP_HPP_

#include <SDL.h>
#include "managers/ResourceManager.hpp"
#include "base/GameObject.hpp"
#include "Util.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "emberetta/objects/PlayerWeaponsFactory.hpp"

/**
 * Represents the player's ship in emberetta
 */
class PlayerShip : public GameObject {
public:
	PlayerShip(float x, float y);

	//Needed a destructor so clang compiles.
	//virtual ~Player() = 0;

	std::ostream& print(std::ostream &out) override;

	/**
	 * Returns the result of firing the ships weapon
	 */
	std::vector<std::shared_ptr<GameObject>> fireWeapon();

private:
	float initX,initY;
};

#endif
