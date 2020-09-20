/*
 * Background.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#include "platformance/objects/Background.hpp"
#include "platformance/ObjectTypes.hpp"
#include "base/GameObject.hpp"
#include "platformance/components/ParallaxBackgroundTextureRenderComponent.hpp"
#include "base/PhysicsComponent.hpp"


Background::Background(int frame, int scrollSpeed):
GameObject(0, 0, 1280, 720, TAG_BACKGROUND) {
	m_frame = frame;
	m_speed = scrollSpeed;
	std::stringstream ss;
	ss << "forest/"<< frame << ".png";
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	SDL_Rect src{0, 0, 1920, 1080};
	setRenderComponent(std::make_shared<ParallaxBackgroundTextureRenderComponent>(*this, ss.str(), src, m_speed/10.0));
}

std::ostream& Background::print(std::ostream &out) {
	return out << TAG_BACKGROUND << " " << m_frame << " " << m_speed << std::endl;
}


