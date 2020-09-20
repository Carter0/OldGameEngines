/*
 * Spawner.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#pragma once

#include "base/GameObject.hpp"
#include "emberetta/ObjectTypes.hpp"

class Spawner : public GameObject {
public:
	Spawner(float x, float y, int spawnSpeed, int delay, int maxSpawns, int spawnType);
	std::ostream& print(std::ostream &out) override;
	std::string typeCheck() override;

private:
	int spawnSpeed, delay, maxSpawns, spawnType;
};

class RandomSpawner : public GameObject {
public:
	RandomSpawner(float x, float y, int spawnSpeed, int delay);
	std::ostream& print(std::ostream &out) override;
	std::string typeCheck() override;

private:
	int spawnSpeed, delay;
};
