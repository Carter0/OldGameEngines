/*
 * EnemyBullet.cpp
 *
 *  Created on: Apr 5, 2020
 *      Author: jaked
 */

#include "emberetta/objects/EnemyBullet.hpp"
#include "emberetta/components/TimedExplode.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/AddPointsOnCollisionComponent.hpp"
#include "base/TextureRenderComponent.hpp"
#include "base/RectRenderComponent.hpp"
#include <SDL.h>

using namespace EmberettaObjects;

EnemyBullet::EnemyBullet(float x, float y,float w, float h) : GameObject(x, y, w, h, TAG_ENEMYBULLET) {

}
EnemyBullet::EnemyBullet(float x, float y,float w, float h, int tag) : GameObject(x, y, w, h, tag) {

}

std::ostream& EnemyBullet::print(std::ostream &out) {
	return out;
}

EnemyPellet::EnemyPellet(float x, float y, float speedX, float speedY) : EnemyBullet (x, y, 10.0f, 10.0f) {
	std::shared_ptr<PhysicsComponent> pc = std::make_shared<PhysicsComponent>(*this, false);
	pc->setVx(speedX);
	pc->setVy(speedY);
	setPhysicsComponent(pc);
	SDL_Rect src{6, 7, 10, 11};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "bullets.png", src));
}


EnemyBomb::EnemyBomb(float x, float y, float speedX, float speedY) : EnemyBullet (x, y, 20.0f, 20.0f, TAG_BOMB) {
	std::shared_ptr<PhysicsComponent> pc = std::make_shared<PhysicsComponent>(*this, false);
	pc->setVx(speedX);
	pc->setVy(speedY);
	setPhysicsComponent(pc);
	SDL_Rect src{0, 0, 15, 15};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "bombs.png", src));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_BOMBDELETER));
	addGenericComponent(std::make_shared<TimedExplode>(*this, 2500));
}

BombDeleter::BombDeleter(float x, float y, float speedX, float speedY) : GameObject (x, y, 1.0f, 1.0f, TAG_BOMBDELETER) {
	std::shared_ptr<PhysicsComponent> pc = std::make_shared<PhysicsComponent>(*this, false);
	pc->setVx(speedX);
	pc->setVy(speedY);
	setPhysicsComponent(pc);
    setRenderComponent(std::make_shared<RectRenderComponent>(*this, 255,0,0));
	addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, EmberettaObjects::TAG_BOMB));
}





