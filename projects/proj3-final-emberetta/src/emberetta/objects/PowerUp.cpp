/*
 * PowerUp.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */

#include "emberetta/objects/PowerUp.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "emberetta/components/PowerUpComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/TextureRenderComponent.hpp"

PowerUp::PowerUp(float x, float y) : GameObject (x,y,30.0f,30.0f,EmberettaObjects::TAG_POWERUP) {
	m_type = static_cast<PowerUpType>(rand() % (PowerUpType::RED + 1));
	std::shared_ptr<PhysicsComponent> pc = std::make_shared<PhysicsComponent>(*this, false);
	pc->setVy(1);
	setPhysicsComponent(pc);
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "spaceships_spritesheet.png", getSprite()));
	addGenericComponent(std::make_shared<PowerUpComponent>(*this, m_type,EmberettaObjects::TAG_PLAYERSHIP));
}

std::ostream& PowerUp::print(std::ostream &out) {
	// Not printed
	return out;
}

SDL_Rect PowerUp::getSprite() {
 	switch(m_type) {
	case PowerUpType::GREEN:
		return SDL_Rect{ 369,370,62,61};
	case PowerUpType::PURPLE:
		return SDL_Rect{ 483,370,62,61};
	case PowerUpType::BLUE:
		return SDL_Rect{ 596,370,62,61};
	case PowerUpType::RED:
		return SDL_Rect{ 711,370,62,61};
	default:
		return SDL_Rect{ 711,370,62,61};
	}
}

