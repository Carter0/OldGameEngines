#pragma once

#include "base/GameObject.hpp"

//! \brief A class representing the ball in breakout.
class Ball : public GameObject {
public:
    Ball(float x, float y, float w, float h);

    std::ostream& print(std::ostream &out) override;

    std::string typeCheck() override;

private:
    float initX;
    float initY;
};
