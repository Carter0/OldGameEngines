/*
 * ObjectTypes.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTTYPES_HPP_
#define INCLUDE_EMBERETTA_OBJECTTYPES_HPP_

#include "emberetta/objects/PlayerShip.hpp"
#include "emberetta/objects/EnemyBullet.hpp"
#include "emberetta/objects/EmberettaBackground.hpp"
#include "base/GenericObjectTypes.hpp"



//! \brief A file which defines various types of game objects, and tags them appropriately for Emberetta.
namespace EmberettaObjects {
// Reserving 0-5 as other game related parameters
// These will match the level loading object types
// Left some room for who knows what
// Not created by the editor

//Editor Values
static const int TAG_SPAWNER = 4;
static const int TAG_RANDOMSPAWNER = 42;
static const int TAG_PLAYERSHIP = 5;
static const int TAG_PLAYERBULLET = 80;
static const int TAG_ENEMYBULLET = 81;
static const int TAG_BOMBDELETER = 82;
static const int TAG_BOMB = 83;
static const int TAG_POWERUP = 84;

static const int TAG_ENEMYSHIP = 6;
static const int TAG_ENEMYFIGHTER = 7;
static const int TAG_ENEMYBOMBER = 8;
static const int TAG_ENEMYINTERCEPTOR = 9;

//Not inserted Manually
static const int TAG_GAMECONTROLLER = 90;
static const int TAG_YOUWIN = 91;
static const int TAG_SCORE = 92;
static const int TAG_LIVES = 93;

static const float PELLET_SPEED = 3.0f;

}

#endif /* INCLUDE_EMBERETTA_OBJECTTYPES_HPP_ */
