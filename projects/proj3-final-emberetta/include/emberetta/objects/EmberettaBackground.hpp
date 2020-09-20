/*
 * EmberettaBackground.hpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTS_EMBERETTABACKGROUND_HPP_
#define INCLUDE_EMBERETTA_OBJECTS_EMBERETTABACKGROUND_HPP_

#include <SDL.h>

#include "base/GameObject.hpp"
#include "platformance/ObjectTypes.hpp"

class EmberettaBackground: public GameObject {
public:
	EmberettaBackground(int frame, float speed);

	std::ostream& print(std::ostream &out) override;
private:
	float m_speed;
	int m_frame;
};



#endif /* INCLUDE_EMBERETTA_OBJECTS_EMBERETTABACKGROUND_HPP_ */
