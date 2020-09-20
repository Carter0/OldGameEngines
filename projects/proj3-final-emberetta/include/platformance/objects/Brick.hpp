/*
 * Brick.hpp
 *
 *  Created on: Feb 22, 2020
 *      Author: 
 */

#pragma once
#ifndef BRICK_HPP_
#define BRICK_HPP_

#include <SDL.h>

#include "base/GameObject.hpp"
#include "platformance/ObjectTypes.hpp"

//! \brief A class for representing a single brick in the game world.
class Brick: public GameObject {
public:
	Brick(float x, float y, float w, float h);
	//virtual ~Brick() = 0;

	std::ostream& print(std::ostream &out) override;
};

#endif
