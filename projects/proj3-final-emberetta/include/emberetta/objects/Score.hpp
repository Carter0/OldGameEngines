#pragma once
#ifndef SCORE_E_HPP_
#define SCORE_E_HPP_

#include <SDL.h>
#include "base/GameObject.hpp"
#include "emberetta/Emberetta.hpp"

//! \brief A class to hold the score text.
class EmbScore: public GameObject {
public:
	EmbScore(float x, float y, float w, float h, Emberetta* level);

	std::ostream& print(std::ostream &out) override;
};

#endif