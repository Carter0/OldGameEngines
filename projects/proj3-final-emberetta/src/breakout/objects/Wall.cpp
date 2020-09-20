#include "breakout/objects/Wall.hpp"
#include "base/RectRenderComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "breakout/ObjectTypes.hpp"
 
Wall::Wall(float x, float y, float w, float h) : GameObject(x, y, w, h, BreakoutObjects::TAG_WALL) {
    setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, true));
    setRenderComponent(std::make_shared<RectRenderComponent>(*this, 0, 150, 150));
}

std::ostream& Wall::print(std::ostream &out) {
	return out << BreakoutObjects::TAG_WALL << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}