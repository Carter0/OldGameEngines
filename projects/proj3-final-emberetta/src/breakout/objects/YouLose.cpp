
#include "breakout/objects/YouLose.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/LoseRenderComponent.hpp"

YouLose::YouLose(Level * level): GameObject(0, 0, 0, 0, BreakoutObjects::TAG_YOULOSE) {
    setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderComponent(std::make_shared<LoseRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& YouLose::print(std::ostream &out) {
	return out;
}



