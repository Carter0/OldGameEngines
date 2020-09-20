/*
 * Coin.hpp
 *
 *  Created on: Feb 22, 2020
 *      Author: 
 */

#pragma once
#ifndef COIN_HPP_
#define COIN_HPP_

#include <SDL.h>

#include "base/GameObject.hpp"
#include "platformance/ObjectTypes.hpp"

//! \brief A class for representing a single coin in the game world.
class Coin: public GameObject {
public:
	Coin(float x, float y, float w, float h);
	//virtual ~Coin() = 0;

	std::ostream& print(std::ostream &out) override;
};

#endif
