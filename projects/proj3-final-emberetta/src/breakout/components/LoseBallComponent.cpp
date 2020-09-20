#include "breakout/components/LoseBallComponent.hpp"
#include "breakout/components/BallPhysicsComponent.hpp"

LoseBallComponent::LoseBallComponent(GameObject & gameObject): GenericComponent(gameObject) {}

void LoseBallComponent::update(Level & level) {

    std::shared_ptr<PhysicsComponent> pc = gameObject().physicsComponent();
    if (gameObject().y() + gameObject().h() > level.h() && dynamic_cast<Breakout*>(&level)->balls == 1) {
        gameObject().setY(level.h() / 1.5);
        gameObject().setX(level.w() / 2);
        pc->setVy(-9);
        pc->setVx(9);
        AudioManager::getInstance().playSound("die.wav");
        level.loseLife();
    } else if (gameObject().y() + gameObject().h() > level.h()) {
    	dynamic_cast<Breakout*>(&level)->balls--;
    }
}
