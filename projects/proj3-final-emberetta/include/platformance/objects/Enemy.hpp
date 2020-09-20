/*
 * Enemy.hpp
 *
 *  Created on: March 14, 2020
 *      Author: Carter Weinberg
 */

#pragma once

#include <SDL.h>
#include "managers/ResourceManager.hpp"
#include "base/GameObject.hpp"
#include "Util.hpp"
#include "platformance/ObjectTypes.hpp"

//! \brief A class for representing a single enemy in the game world.
class Enemy: public GameObject {
public:
	Enemy(float x, float y, float w, float h);
	//virtual ~Enemy() = 0;

	std::ostream& print(std::ostream &out) override;

private:
	float initX;//this enemy's x value at the moment of initialization
	float initY;//this enemy's y value at the moment of initialization

};
