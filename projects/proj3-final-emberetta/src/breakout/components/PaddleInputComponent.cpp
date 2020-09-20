#include "breakout/components/PaddleInputComponent.hpp"
#include "managers/InputManager.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/GameObject.hpp"


PaddleInputComponent::PaddleInputComponent(GameObject & gameObject, float speed):
	GenericComponent(gameObject),
	mSpeed(speed) {}


void PaddleInputComponent::update(Level & level)
{
	bool left = InputManager::getInstance().isKeyDown(SDLK_LEFT);
	bool right = InputManager::getInstance().isKeyDown(SDLK_RIGHT);

	std::shared_ptr<PhysicsComponent> pc = gameObject().physicsComponent();

	if (left && !right) {
		pc->setVx(-mSpeed);
	} else if (!left && right) {
		pc->setVx(mSpeed);
	} else {
		pc->setVx(0.0f);
	}
}


