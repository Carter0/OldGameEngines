#pragma once

#include "base/GenericComponent.hpp"
#include "emberetta/objects/Spawner.hpp"

//! \brief Component for handling (keyboard) input in emberetta
class SpawnerComponent: public GenericComponent {
public:
	//the spawner component keeps track of how often a unit is spawned, how long it takes before units start spawning, and how many units the factory will spawn
	SpawnerComponent(Spawner & gameObject, int spawnSpeed, int delay, int maxSpawns, int spawnType);

	virtual void update(Level & level) override;

private:
	int maxSpawns = 5, countdown = 0, spawnSpeed = 300, delay = 300, spawnType;

};

class RandomSpawnerComponent: public GenericComponent {
public:
	//the spawner component keeps track of how often a unit is spawned, how long it takes before units start spawning, and how many units the factory will spawn
	RandomSpawnerComponent(RandomSpawner & gameObject, int spawnSpeed, int delay);
	virtual void update(Level & level) override;

private:
	int countdown = 0, spawnSpeed = 300, delay = 300;

};
