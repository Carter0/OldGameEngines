#include "emberetta/components/SpawnerComponent.hpp"
#include "emberetta/objects/EnemyShip.hpp"
#include "emberetta/behaviors/StateMachineFactory.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"

SpawnerComponent::SpawnerComponent(Spawner & gameObject, int spawnSpeed, int delay, int maxSpawns, int spawnType): GenericComponent(gameObject) {
	this->spawnSpeed = spawnSpeed;
	this->delay = delay;
	this->maxSpawns = maxSpawns;
	this->spawnType = spawnType;
}

void SpawnerComponent::update(Level & level) {
	countdown++;
	if (countdown >= delay + spawnSpeed && maxSpawns > 0) {
		if (spawnType == EmberettaObjects::TAG_ENEMYSHIP) {
			level.addObject(std::make_shared<EnemyShip>(gameObject().x(), gameObject().y()));
		} else if (spawnType == EmberettaObjects::TAG_ENEMYFIGHTER) {
			level.addObject(std::make_shared<EnemyFighter>(gameObject().x(), gameObject().y()));
		} else if (spawnType == EmberettaObjects::TAG_ENEMYBOMBER) {
			level.addObject(std::make_shared<EnemyBomber>(gameObject().x(), gameObject().y()));
		} else if (spawnType == EmberettaObjects::TAG_ENEMYINTERCEPTOR) {
			level.addObject(std::make_shared<EnemyInterceptor>(gameObject().x(), gameObject().y()));
		}
		countdown = delay;
		maxSpawns--;
	}
}

RandomSpawnerComponent::RandomSpawnerComponent(RandomSpawner & gameObject, int spawnSpeed, int delay): GenericComponent(gameObject) {
	this->spawnSpeed = spawnSpeed;
	this->delay = delay;
}

void RandomSpawnerComponent::update(Level & level) {
	countdown++;
	if (countdown >= delay + spawnSpeed) {
		std::shared_ptr<GameObject> newShip;
		float spawnX = 90.0f + rand()%460;
		switch(rand()%3) {
		case 0:
			newShip = std::make_shared<EnemyFighter>(spawnX,gameObject().y());
			break;
		case 1:
			newShip = std::make_shared<EnemyBomber>(spawnX,gameObject().y());
			break;
		case 2:
			newShip = std::make_shared<EnemyInterceptor>(spawnX,gameObject().y());
			break;
		}

		switch(rand()%2) {
		case 0:{
			std::shared_ptr<StateComponent::State> stationary = std::make_shared<StationaryState>();
			std::shared_ptr<StateComponent::State> sweep = std::make_shared<BounceState>(2.0f, 1.0f);
			std::shared_ptr<StateComponent> sc = std::make_shared<StateComponent>(*newShip);
			sc->setStartState(stationary);
			sc->addTransition(stationary, sweep, std::make_shared<TimedTransition>(60));
			newShip->addGenericComponent(sc);
			break;
		}
		case 1:{
			std::shared_ptr<StateComponent::State> stationary = std::make_shared<StationaryState>();
			std::shared_ptr<StateComponent::State> straight = std::make_shared<MoveAcrossState>(0.0f,3.0f);
			std::shared_ptr<StateComponent> sc = std::make_shared<StateComponent>(*newShip);
			sc->setStartState(stationary);
			sc->addTransition(stationary, straight, std::make_shared<TimedTransition>(60));
			newShip->addGenericComponent(sc);
			break;
		}
		}
		level.addObject(newShip);
		countdown = delay;
	}
}
