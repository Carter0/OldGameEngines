#include "emberetta/objects/Score.hpp"
#include "base/ScoreRenderComponent.hpp"
#include "emberetta/ObjectTypes.hpp"



EmbScore::EmbScore(float x, float y, float w, float h, Emberetta* level): GameObject(x, y, w, h, EmberettaObjects::TAG_SCORE) {
    setRenderComponent(std::make_shared<ScoreRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& EmbScore::print(std::ostream &out) {
	return out << EmberettaObjects::TAG_SCORE << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}