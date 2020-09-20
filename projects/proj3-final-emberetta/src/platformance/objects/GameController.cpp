#include "base/GameObject.hpp"
#include "platformance/objects/GameController.hpp"
#include "base/ScoreRenderComponent.hpp"


GameController::GameController(float x, float y, float w, float h, Platformance* level): GameObject(x, y, w, h, PlatformanceObjects::TAG_GAMECONTROLLER) {
    setRenderComponent(std::make_shared<ScoreRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& GameController::print(std::ostream &out) {
	return out << PlatformanceObjects::TAG_GAMECONTROLLER << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}
