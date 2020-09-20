#pragma once

#include <SDL.h>
#include "base/GameObject.hpp"
#include "platformance/ObjectTypes.hpp"

//! \brief A class to represent the goal object in the game world.
class Goal: public GameObject {
public:
	Goal(float x, float y, float w, float h, int level);

	std::ostream& print(std::ostream &out) override;

	std::string typeCheck() override;

private:
	unsigned int m_level;
};

