/*
 * FriendlyBullet.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#include "emberetta/objects/FriendlyBullet.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/TextureRenderComponent.hpp"
#include "base/AddPointsOnCollisionComponent.hpp"
#include <SDL.h>

FriendlyBullet::FriendlyBullet(float x, float y, float speed): GameObject(x, y, 10, 10, EmberettaObjects::TAG_PLAYERBULLET) {
	std::shared_ptr<PhysicsComponent> pc = std::make_shared<PhysicsComponent>(*this, false);
	pc->setVy(-10);
	setPhysicsComponent(pc);
	SDL_Rect src{6, 18, 5, 12};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "bullets.png", src));
}

FriendlyBullet::FriendlyBullet(float x, float y, float w, float h): GameObject(x, y, w, h, EmberettaObjects::TAG_PLAYERBULLET) {
}

std::ostream& FriendlyBullet::print(std::ostream &out) {
	// Not printed
	return out;
}

FriendlyBulletTwo::FriendlyBulletTwo(float x, float y, float speedX, float speedY): FriendlyBullet(x, y, 10, 10) {
	std::shared_ptr<PhysicsComponent> pc = std::make_shared<PhysicsComponent>(*this, false);
	pc->setVx(speedX);
	pc->setVy(speedY);
	setPhysicsComponent(pc);
	SDL_Rect src{240, 61, 12, 12};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "bullets_spritesheet.png", src));
}


FriendlyLaser::FriendlyLaser(float x, float y, float speedX, float speedY): FriendlyBullet(x, y, 8, 16) {
	std::shared_ptr<PhysicsComponent> pc = std::make_shared<PhysicsComponent>(*this, false);
	pc->setVx(speedX);
	pc->setVy(speedY);
	setPhysicsComponent(pc);
	SDL_Rect src{153, 58, 8, 18};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "bullets_spritesheet.png", src));
    addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_ENEMYBULLET));
}

