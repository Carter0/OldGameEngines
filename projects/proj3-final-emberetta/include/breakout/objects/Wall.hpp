#pragma once
#ifndef WALL_HPP_
#define WALL_HPP_

#include "base/GameObject.hpp"

//! \brief A class representing the walls in breakout.
class Wall : public GameObject {
public:
    Wall(float x, float y, float w, float h);

    std::ostream& print(std::ostream &out) override;
};

#endif