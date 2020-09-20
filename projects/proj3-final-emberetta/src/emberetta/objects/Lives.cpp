#include "emberetta/objects/Lives.hpp"
#include "base/LivesRenderComponent.hpp"
#include "emberetta/ObjectTypes.hpp"

EmbLives::EmbLives(float x, float y, float w, float h, Emberetta* level): GameObject(x, y, w, h, EmberettaObjects::TAG_LIVES) {
    setRenderComponent(std::make_shared<LivesRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& EmbLives::print(std::ostream &out) {
	return out << EmberettaObjects::TAG_LIVES << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}