/*
 * EmberettaBackground.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#include "emberetta/objects/EmberettaBackground.hpp"
#include "emberetta/components/BackgroundRenderComponent.hpp"

EmberettaBackground::EmberettaBackground(int frame, float scrollSpeed):
GameObject(0, 0, 640, 800, TAG_BACKGROUND) {
	m_frame = frame;
	m_speed = scrollSpeed;
	std::stringstream ss;
	ss << "space/"<< frame << ".png";
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
	SDL_Rect src{0, 0, 4096, 4096};
	setRenderComponent(std::make_shared<BackgroundRenderComponent>(*this, ss.str(), src, scrollSpeed));
}

std::ostream& EmberettaBackground::print(std::ostream &out) {
	return out << TAG_BACKGROUND << " " << m_frame << " " << m_speed << std::endl;
}

