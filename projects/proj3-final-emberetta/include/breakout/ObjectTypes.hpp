//! \brief A file which defines various types of game objects, and tags them appropriately for breakout.

#ifndef INCLUDE_OBJECTTYPES_BREAKOUT_HPP_
#define INCLUDE_OBJECTTYPES_BREAKOUT_HPP_

#include "objects/Ball.hpp"
#include "objects/Block.hpp"
#include "objects/Paddle.hpp"


namespace BreakoutObjects {

//Editor Values
static const int TAG_BLOCK = 5;
static const int TAG_PADDLE = 6;
static const int TAG_BALL = 7;
static const int TAG_WALL = 8;

//Not inserted Manually
static const int TAG_SCORE = 90;
static const int TAG_LIVES = 91;
static const int TAG_YOULOSE = 92;
}


#endif /* INCLUDE_OBJECTTYPES_HPP_ */
