#include "breakout/objects/Block.hpp"

#include "base/RectRenderComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "breakout/ObjectTypes.hpp"

 
Block::Block(float x, float y, float w, float h) : GameObject(x, y, w, h, BreakoutObjects::TAG_BLOCK) {
    setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, true));
    setRenderComponent(std::make_shared<RectRenderComponent>(*this, 200, 100, 200));
}

std::ostream& Block::print(std::ostream &out) {
	return out << BreakoutObjects::TAG_BLOCK << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}

std::string Block::typeCheck() {
	return "Block";
}
