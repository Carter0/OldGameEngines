#include "platformance/objects/Enemy.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/SoundOnCollideComponent.hpp"
#include "base/PatrolComponent.hpp"
#include "base/TextureRenderComponent.hpp"

Enemy::Enemy(float x, float y, float w, float h): GameObject(x, y, w, h, TAG_ENEMY) {
    addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_PLAYER));
    addGenericCompenent(std::make_shared<SoundOnCollideComponent>(*this, TAG_PLAYER, "Hurt.ogg"));
    addGenericCompenent(std::make_shared<PatrolComponent>(*this, x + 50, y + 100, 2.0f));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
    SDL_Rect src{0, 0, 25, 26};
    setRenderCompenent(std::make_shared<TextureRenderComponent>(*this, "bee_spritesheet.png", src));
    initX = x;
    initY = y;
}

//Enemy::~Enemy(){};

std::ostream& Enemy::print(std::ostream &out) {
	return out << TAG_ENEMY << " " << initX << " " << initY << " " << this->w() << " " << this->h() << std::endl;
}
