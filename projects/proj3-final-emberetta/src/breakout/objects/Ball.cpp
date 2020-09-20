#include "breakout/objects/Ball.hpp"

#include "base/RectRenderComponent.hpp"
#include "breakout/components/LoseBallComponent.hpp"
#include "breakout/components/BallPhysicsComponent.hpp"
#include "breakout/ObjectTypes.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/AddPointsOnCollisionComponent.hpp"
#include "base/SoundOnCollideComponent.hpp"

 
Ball::Ball(float x, float y, float w, float h) : GameObject(x, y, w, h, BreakoutObjects::TAG_BALL) {
    setPhysicsComponent(std::make_shared<BallPhysicsComponent>(*this, false, 9, 9));
    setRenderComponent(std::make_shared<RectRenderComponent>(*this, 0, 255, 255));
    addGenericComponent(std::make_shared<LoseBallComponent>(*this));
    addGenericComponent(std::make_shared<SoundOnCollideComponent>(*this, BreakoutObjects::TAG_BLOCK, "block.wav"));
    addGenericComponent(std::make_shared<SoundOnCollideComponent>(*this, BreakoutObjects::TAG_WALL, "invincible.wav"));
    addGenericComponent(std::make_shared<SoundOnCollideComponent>(*this, BreakoutObjects::TAG_PADDLE, "paddle.wav"));
    addGenericComponent(std::make_shared<AddPointsOnCollisionComponent>(*this, BreakoutObjects::TAG_BLOCK, 10));
    addGenericComponent(std::make_shared<RemoveOnCollideComponent>(*this, BreakoutObjects::TAG_BLOCK));
    initX = x;
    initY = y;
}

std::ostream& Ball::print(std::ostream &out) {
	return out << BreakoutObjects::TAG_BALL << " " << initX << " " << initY << " " << this->w() << " " << this->h() << std::endl;
}

std::string Ball::typeCheck() {
	return "Ball";
}
