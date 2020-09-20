/*
 * YouWin.hpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_PLATFORMANCE_OBJECTS_YOUWIN_HPP_
#define INCLUDE_PLATFORMANCE_OBJECTS_YOUWIN_HPP_

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



#endif /* INCLUDE_PLATFORMANCE_OBJECTS_YOUWIN_HPP_ */
