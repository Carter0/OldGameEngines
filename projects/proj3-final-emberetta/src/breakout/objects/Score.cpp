#include "breakout/objects/Score.hpp"
#include "base/ScoreRenderComponent.hpp"
#include "breakout/ObjectTypes.hpp"



Score::Score(float x, float y, float w, float h, Breakout* level): GameObject(x, y, w, h, BreakoutObjects::TAG_SCORE) {
    setRenderComponent(std::make_shared<ScoreRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& Score::print(std::ostream &out) {
	return out << BreakoutObjects::TAG_SCORE << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}