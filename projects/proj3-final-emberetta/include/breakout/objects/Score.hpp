#pragma once
#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <SDL.h>
#include "base/GameObject.hpp"
#include "breakout/Breakout.hpp"

//! \brief A class to hold the score text.
class Score: public GameObject {
public:
	Score(float x, float y, float w, float h, Breakout* level);

	std::ostream& print(std::ostream &out) override;
};

#endif