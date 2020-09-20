#include "base/GameObject.hpp"
#include "platformance/objects/Goal.hpp"
#include "base/LoadLevelComponent.hpp"
#include "base/TextureRenderComponent.hpp"

Goal::Goal(float x, float y, float w, float h, int level):
    GameObject(x, y, w, h, PlatformanceObjects::TAG_GOAL)
{
	m_level = level;
    addGenericComponent(std::make_shared<LoadLevel>(*this, m_level, PlatformanceObjects::TAG_PLAYER));
    setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));

    SDL_Rect src{82, 69, 92, 118};
    setRenderComponent(std::make_shared<TextureRenderComponent>(*this, "flag.png", src));
}

std::ostream& Goal::print(std::ostream &out) {
	return out << PlatformanceObjects::TAG_GOAL << " " << this->x() << " " << this->y() << " " << this->w() << " " << this->h() << " " << m_level << std::endl;
}

std::string Goal::typeCheck() {
	return "Goal";
}

