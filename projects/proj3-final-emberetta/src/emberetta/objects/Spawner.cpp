/*
 * Spawner.cpp
 *
 *  Created on: Apr 5, 2020
 *      Author: sable
 */

#include "emberetta/objects/Spawner.hpp"
#include "emberetta/components/SpawnerComponent.hpp"

Spawner::Spawner(float x, float y, int spawnSpeed, int delay, int maxSpawns, int spawnType): GameObject(x, y, 0, 0, EmberettaObjects::TAG_SPAWNER) {
	this->spawnSpeed = spawnSpeed;
	this->delay = delay;
	this->maxSpawns = maxSpawns;
	this->spawnType = spawnType;
	addGenericComponent(std::make_shared<SpawnerComponent>(*this, spawnSpeed, delay, maxSpawns, spawnType));

}

std::ostream& Spawner::print(std::ostream &out) {
	return out << EmberettaObjects::TAG_SPAWNER << " " << x() << " " << y() << " "
			<< spawnSpeed << " " << delay << " " << maxSpawns << " " << spawnType << std::endl;
}

std::string Spawner::typeCheck() {
	return "Spawner";
}

RandomSpawner::RandomSpawner(float x, float y, int spawnSpeed, int delay): GameObject(x, y, 0, 0, EmberettaObjects::TAG_RANDOMSPAWNER) {
	this->spawnSpeed = spawnSpeed;
	this->delay = delay;
	addGenericComponent(std::make_shared<RandomSpawnerComponent>(*this, spawnSpeed, delay));

}

std::ostream& RandomSpawner::print(std::ostream &out) {
	return out << EmberettaObjects::TAG_RANDOMSPAWNER << " " << x() << " " << y() << " "
			<< spawnSpeed << " " << delay << std::endl;
}

std::string RandomSpawner::typeCheck() {
	return "RandomSpawner";
}


