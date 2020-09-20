#pragma once
#ifndef PADDLE_HPP_
#define PADDLE_HPP_

#include "base/GameObject.hpp"

//! \brief A class representing the paddle in breakout.
class Paddle : public GameObject {
public:
    Paddle(float x, float y, float w, float h);

    std::ostream& print(std::ostream &out) override;

    std::string typeCheck() override;
};

#endif
