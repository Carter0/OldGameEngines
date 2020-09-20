#include "breakout/objects/Lives.hpp"
#include "base/LivesRenderComponent.hpp"
#include "breakout/ObjectTypes.hpp"

Lives::Lives(float x, float y, float w, float h, Breakout* level): GameObject(x, y, w, h, BreakoutObjects::TAG_LIVES) {
    setRenderComponent(std::make_shared<LivesRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& Lives::print(std::ostream &out) {
	return out << BreakoutObjects::TAG_LIVES << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << std::endl;
}