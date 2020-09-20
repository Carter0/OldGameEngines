/*
 * ObjectTypes.hpp
 *
 *  Created on: Mar 9, 2020
 *      Author: jaked
 */

//! \brief A file which defines various types of game objects, and tags them appropriately.

#ifndef INCLUDE_OBJECTTYPES_HPP_
#define INCLUDE_OBJECTTYPES_HPP_

#include "platformance/objects/Player.hpp"
#include "platformance/objects/Brick.hpp"
#include "platformance/objects/Coin.hpp"
#include "platformance/objects/Background.hpp"
#include "platformance/objects/YouWin.hpp"

// Reserving 0-5 as other game related parameters
// These will match the level loading object types
// Left some room for who knows what
// Not created by the editor
static const int TAG_LEVEL_SIZE = 0;
static const int TAG_BACKGROUND_MUSIC = 1;
static const int TAG_EDITOR = 2;
static const int TAG_BACKGROUND = 3;

//Editor Values
static const int TAG_COIN   = 5;
static const int TAG_PLAYER = 6;
static const int TAG_BLOCK  = 7;
static const int TAG_GOAL   = 8;
static const int TAG_ENEMY  = 9;

//Not inserted Manually
static const int TAG_GAMECONTROLLER = 90;
static const int TAG_YOUWIN = 91;

#endif /* INCLUDE_OBJECTTYPES_HPP_ */
