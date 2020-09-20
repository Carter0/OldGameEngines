/*
 * PlayerShip.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */


#include "emberetta/objects/PlayerShip.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "emberetta/components/ShipInputComponent.hpp"
#include "emberetta/components/EmberettaCamera.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/LoseLifeComponent.hpp"
#include "base/SoundOnCollideComponent.hpp"
#include "base/TextureRenderComponent.hpp"
#include "base/StayInWorldComponent.hpp"
#include <SDL.h>

PlayerShip::PlayerShip(float x, float y): GameObject(x, y, 40, 40, EmberettaObjects::TAG_PLAYERSHIP) {

	addGenericComponent(std::make_shared<ShipInputComponent>(*this, 5.0f, 0.0f));
	addGenericComponent(std::make_shared<LoseLifeComponent>(*this, EmberettaObjects::TAG_ENEMYBULLET));
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_ENEMYSHIP));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_ENEMYBULLET));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_POWERUP));
	addGenericComponent(std::make_shared<SoundOnCollideComponent>(*this, EmberettaObjects::TAG_POWERUP, "powerUp.mp3"));
	addGenericComponent(std::make_shared<SoundOnCollideComponent>(*this, EmberettaObjects::TAG_ENEMYBULLET, "explosion2.aiff"));
	SDL_Rect src{32, 24, 16, 48};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "ship.png", src));


	addGenericComponent(std::make_shared<EmberettaCamera>(*this));
	addGenericComponent(std::make_shared<StayInWorldComponent>(*this));


	initX = x;
	initY = y;
}

std::ostream& PlayerShip::print(std::ostream &out) {
	return out << EmberettaObjects::TAG_PLAYERSHIP << " " << initX << " " << initY << std::endl;
}

std::vector<std::shared_ptr<GameObject>> PlayerShip::fireWeapon() {
	return PlayerWeaponsFactory::getInstance().fireWeapon(x()+w()/2, y()+h()/2);
}



