#pragma once
#ifndef LIVES_E_HPP_
#define LIVES_E_HPP_

#include <SDL.h>
#include "base/GameObject.hpp"
#include "emberetta/Emberetta.hpp"

//! \brief A class to hold the lives text.
class EmbLives: public GameObject {
public:
	EmbLives(float x, float y, float w, float h, Emberetta* level);

	std::ostream& print(std::ostream &out) override;
};

#endif