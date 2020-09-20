#include "base/GameObject.hpp"
#include "platformance/objects/GameController.hpp"
#include "base/TextRenderComponent.hpp"


GameController::GameController(float x, float y, float w, float h, Platformance* level): GameObject(x, y, w, h, TAG_GAMECONTROLLER) {
    setRenderCompenent(std::make_shared<TextRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& GameController::print(std::ostream &out) {
	return out << TAG_GAMECONTROLLER << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}
