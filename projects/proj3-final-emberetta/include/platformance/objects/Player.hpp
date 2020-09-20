/*
 * Player.hpp
 *
 *  Created on: Feb 22, 2020
 *      Author: Carter Weinberg
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SDL.h>
#include "managers/ResourceManager.hpp"
#include "base/GameObject.hpp"
#include "Util.hpp"
#include "platformance/ObjectTypes.hpp"

//! \brief A class to represent the player as an object within the game world.
class Player: public GameObject {
public:
	Player(float x, float y, float w, float h);

	//Needed a destructor so clang compiles.
	//virtual ~Player() = 0;

	std::string typeCheck() override;
	std::ostream& print(std::ostream &out) override;

private:
	float initX;//this player's x value at the moment of initialization
	float initY;//this player's y value at the moment of initialization
};

#endif 
