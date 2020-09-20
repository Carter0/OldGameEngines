/*
 * PowerUp.hpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTS_POWERUP_HPP_
#define INCLUDE_EMBERETTA_OBJECTS_POWERUP_HPP_

#include "base/GameObject.hpp"
#include "Util.hpp"
#include "platformance/ObjectTypes.hpp"
#include "SDL.h"


typedef enum PowerUpType { BLUE, GREEN, PURPLE, RED } PowerUpType;

/**
 * Player PowerUps
 */
class PowerUp : public GameObject {
public:

	PowerUp(float x, float y);

	std::ostream& print(std::ostream &out) override;
private:
	PowerUpType m_type;
	SDL_Rect getSprite();

};




#endif /* INCLUDE_EMBERETTA_OBJECTS_POWERUP_HPP_ */
