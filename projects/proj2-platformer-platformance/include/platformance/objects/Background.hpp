/*
 * Background.hpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_PLATFORMANCE_OBJECTS_BACKGROUND_HPP_
#define INCLUDE_PLATFORMANCE_OBJECTS_BACKGROUND_HPP_

#include <SDL.h>

#include "base/GameObject.hpp"
#include "platformance/ObjectTypes.hpp"

class Background: public GameObject {
public:
	Background(int frame, int speed);

	std::ostream& print(std::ostream &out) override;
private:
	int m_speed;
	int m_frame;
};



#endif /* INCLUDE_PLATFORMANCE_OBJECTS_BACKGROUND_HPP_ */
