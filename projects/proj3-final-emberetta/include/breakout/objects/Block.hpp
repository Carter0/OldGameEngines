#pragma once
#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "base/GameObject.hpp"

//! \brief A class representing a block in breakout.
class Block : public GameObject {
public:
    Block(float x, float y, float w, float h);
    std::string typeCheck() override;
    std::ostream& print(std::ostream &out) override;
};

#endif
