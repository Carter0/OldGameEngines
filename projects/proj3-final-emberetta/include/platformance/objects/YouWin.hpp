/*
 * YouWin.hpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#pragma once

#include <SDL.h>
#include "managers/ResourceManager.hpp"
#include "base/GameObject.hpp"
#include "Util.hpp"
#include "platformance/ObjectTypes.hpp"

//! \brief Shows You Win.
class YouWin: public GameObject {
public:
	YouWin(Level * level);

	std::ostream& print(std::ostream &out) override;

};
