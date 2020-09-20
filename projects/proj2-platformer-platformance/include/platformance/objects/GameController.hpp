#pragma once
#ifndef GAME_CONTROLLER_HPP_
#define GAME_CONTROLLER_HPP_

#include <SDL.h>
#include "base/GameObject.hpp"
#include "platformance/ObjectTypes.hpp"
#include "platformance/Platformance.hpp"

//! \brief A class to represent the GameController.
class GameController: public GameObject {
public:
	GameController(float x, float y, float w, float h, Platformance* level);

	std::ostream& print(std::ostream &out) override;
};

#endif
