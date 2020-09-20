#include "breakout/objects/Paddle.hpp"

#include "base/RectRenderComponent.hpp"
#include "breakout/components/PaddleInputComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "breakout/ObjectTypes.hpp"
 
Paddle::Paddle(float x, float y, float w, float h) : GameObject(x, y, w, h, BreakoutObjects::TAG_PADDLE) {
    setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, true));
    addGenericComponent(std::make_shared<PaddleInputComponent>(*this, 10));
    setRenderComponent(std::make_shared<RectRenderComponent>(*this, 102, 102, 255));
}

std::ostream& Paddle::print(std::ostream &out) {
	return out << BreakoutObjects::TAG_PADDLE << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}

std::string Paddle::typeCheck() {
	return "Paddle";
}
