#pragma once

#include <SDL.h>
#include "managers/ResourceManager.hpp"
#include "base/GameObject.hpp"
#include "Util.hpp"
#include "breakout/ObjectTypes.hpp"

//! \brief Shows You Lose.
class YouLose: public GameObject {
public:
	YouLose(Level * level);

	std::ostream& print(std::ostream &out) override;
};
