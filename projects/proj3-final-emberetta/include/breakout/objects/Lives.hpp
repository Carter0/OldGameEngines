#pragma once
#ifndef LIVES_HPP_
#define LIVES_HPP_

#include <SDL.h>
#include "base/GameObject.hpp"
#include "breakout/Breakout.hpp"

//! \brief A class to hold the lives text.
class Lives: public GameObject {
public:
	Lives(float x, float y, float w, float h, Breakout* level);

	std::ostream& print(std::ostream &out) override;
};

#endif