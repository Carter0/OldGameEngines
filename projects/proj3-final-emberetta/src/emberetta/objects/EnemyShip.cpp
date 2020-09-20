/*
 * EnemyShip.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#include "emberetta/objects/EnemyShip.hpp"
#include "emberetta/objects/EnemyBullet.hpp"
#include "emberetta/behaviors/EmberettaStates.hpp"
#include "emberetta/components/GeneratePowerUpOnDestroy.hpp"

#include "base/PhysicsComponent.hpp"
#include "base/AddPointsOnDestroy.hpp"
#include "base/StatesAndTransitions.hpp"
#include "base/StateComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/LoseLifeComponent.hpp"
#include "base/TextureRenderComponent.hpp"
#include "emberetta/components/ShipLifeComponent.hpp"
#include "base/SoundOnDestroyComponent.hpp"
#include <iostream>



/**
 * Creates a generic enemy ship.
 */
EnemyShip::EnemyShip(float x, float y): GameObject(x, y, 50, 50, EmberettaObjects::TAG_ENEMYSHIP) {
	shipTag = EmberettaObjects::TAG_ENEMYSHIP;
	/**
	 * Movement
	 */
	std::shared_ptr<StateComponent::State> stationary = std::make_shared<StationaryState>();
	std::shared_ptr<StateComponent::State> sweep = std::make_shared<BounceState>(2.0f, 1.0f);
	std::shared_ptr<StateComponent> sc = std::make_shared<StateComponent>(*this);
	sc->setStartState(stationary);
	sc->addTransition(stationary, sweep, std::make_shared<TimedTransition>(60));
	addGenericComponent(sc);

	/**
	 * Fire
	 */
	std::shared_ptr<StateComponent::State> noFire = std::make_shared<IdleState>();
	std::shared_ptr<StateComponent::State> fire = std::make_shared<FireState>(this, 2000);
	std::shared_ptr<StateComponent> sc2 = std::make_shared<StateComponent>(*this);
	sc2->setStartState(noFire);
	sc2->addTransition(noFire, fire, std::make_shared<TimedTransition>(30));
	addGenericComponent(sc2);

	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));

	SDL_Rect src{0, 0, 16, 16};
	setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "interceptor.png", src));

	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_PLAYERBULLET));
	addGenericComponent(std::make_shared<LoseLifeComponent>(*this, EmberettaObjects::TAG_PLAYERSHIP));
	addGenericComponent(std::make_shared<ShipLifeComponent>(*this, this,EmberettaObjects::TAG_PLAYERBULLET, 5));
	addGenericComponent(std::make_shared<AddPointsOnDestroy>(*this, 50));
}

EnemyShip::EnemyShip(float x, float y, float w, float h, int subType): GameObject(x, y, w, h, EmberettaObjects::TAG_ENEMYSHIP) {
	shipTag = subType;
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_PLAYERBULLET));
	addGenericComponent(std::make_shared<GeneratePowerUpOnDestroy>(*this, 1.0f));
	addGenericComponent(std::make_shared<LoseLifeComponent>(*this, EmberettaObjects::TAG_PLAYERSHIP));
	addGenericComponent(std::make_shared<SoundOnDestroyComponent>(*this, "explosion.aiff"));
}

std::ostream& EnemyShip::print(std::ostream &out) {
	return out << shipTag << " " << x() << " " << y() << std::endl;
}

std::vector<std::shared_ptr<EnemyBullet>> EnemyShip::fire() {
	std::vector<std::shared_ptr<EnemyBullet>> bullets;
	bullets.push_back(std::make_shared<EnemyPellet>(x()+w()/2, y()+h(), 0.0f, EmberettaObjects::PELLET_SPEED));
	return bullets;
}

EnemyFighter::EnemyFighter(float x, float y): EnemyShip(x, y, shipW, shipH, shipType) {
	shipTag = shipType;
	std::shared_ptr<StateComponent::State> noFire = std::make_shared<IdleState>();
	std::shared_ptr<StateComponent::State> fire = std::make_shared<FireState>(this, 2000);
	std::shared_ptr<StateComponent> sc2 = std::make_shared<StateComponent>(*this);
	sc2->setStartState(noFire);
	sc2->addTransition(noFire, fire, std::make_shared<TimedTransition>(30));
	addGenericComponent(sc2);
	SDL_Rect src{0, 0, 32, 16};
	setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "fighter.png", src));
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_PLAYERBULLET));
	addGenericComponent(std::make_shared<LoseLifeComponent>(*this, EmberettaObjects::TAG_PLAYERSHIP));
	addGenericComponent(std::make_shared<ShipLifeComponent>(*this, this,EmberettaObjects::TAG_PLAYERBULLET, 2));
	addGenericComponent(std::make_shared<AddPointsOnDestroy>(*this, 20));
}

std::vector<std::shared_ptr<EnemyBullet>> EnemyFighter::fire() {
	std::vector<std::shared_ptr<EnemyBullet>> bullets;
	bullets.push_back(std::make_shared<EnemyPellet>(x()+w()/2, y()+h(), 0.0f, EmberettaObjects::PELLET_SPEED));
	bullets.push_back(std::make_shared<EnemyPellet>(x()+w()/2, y()+h(), 1.0f, EmberettaObjects::PELLET_SPEED));
	bullets.push_back(std::make_shared<EnemyPellet>(x()+w()/2, y()+h(), -1.0f, EmberettaObjects::PELLET_SPEED));
	return bullets;
}

EnemyBomber::EnemyBomber(float x, float y): EnemyShip(x, y, shipW, shipH, shipType) {
	shipTag = shipType;
	std::shared_ptr<StateComponent::State> noFire = std::make_shared<IdleState>();
	std::shared_ptr<StateComponent::State> fire = std::make_shared<FireState>(this, 3000);
	std::shared_ptr<StateComponent> sc2 = std::make_shared<StateComponent>(*this);
	sc2->setStartState(noFire);
	sc2->addTransition(noFire, fire, std::make_shared<TimedTransition>(30));
	addGenericComponent(sc2);
	SDL_Rect src{0, 0, 32, 32};
	setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "bomber.png", src));
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_PLAYERBULLET));
	addGenericComponent(std::make_shared<LoseLifeComponent>(*this, EmberettaObjects::TAG_PLAYERSHIP));
	addGenericComponent(std::make_shared<ShipLifeComponent>(*this, this,EmberettaObjects::TAG_PLAYERBULLET, 3));
	addGenericComponent(std::make_shared<AddPointsOnDestroy>(*this, 30));

}

std::vector<std::shared_ptr<EnemyBullet>> EnemyBomber::fire() {
	std::vector<std::shared_ptr<EnemyBullet>> bullets;
	bullets.push_back(std::make_shared<EnemyBomb>(x()+w()/2, y()+h(), 0.0f, EmberettaObjects::PELLET_SPEED));
	return bullets;
}

EnemyInterceptor::EnemyInterceptor(float x, float y): EnemyShip(x, y, shipW, shipH, shipType) {
	shipTag = shipType;
	std::shared_ptr<StateComponent::State> noFire = std::make_shared<IdleState>();
	std::shared_ptr<StateComponent::State> fire = std::make_shared<FireState>(this, 1000);
	std::shared_ptr<StateComponent> sc2 = std::make_shared<StateComponent>(*this);
	sc2->setStartState(noFire);
	sc2->addTransition(noFire, fire, std::make_shared<TimedTransition>(30));
	addGenericComponent(sc2);
	SDL_Rect src{0, 0, 16, 16};
	setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "interceptor.png", src));
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_PLAYERBULLET));
	addGenericComponent(std::make_shared<LoseLifeComponent>(*this, EmberettaObjects::TAG_PLAYERSHIP));
	addGenericComponent(std::make_shared<ShipLifeComponent>(*this, this,EmberettaObjects::TAG_PLAYERBULLET, 1));
	addGenericComponent(std::make_shared<AddPointsOnDestroy>(*this, 10));
}

std::vector<std::shared_ptr<EnemyBullet>> EnemyInterceptor::fire() {
	std::vector<std::shared_ptr<EnemyBullet>> bullets;
	bullets.push_back(std::make_shared<EnemyPellet>(x()+w()/2, y()+h(), 0.0f, EmberettaObjects::PELLET_SPEED));
	return bullets;
}

