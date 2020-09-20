/*
 * CenterText.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */


#include "base/CenterText.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/TextRenderComponent.hpp"

CenterText::CenterText(Level * level, int localeTag): GameObject(0, 0, 0, 0, TAG_CENTERTEXT) {
    setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderComponent(std::make_shared<TextRenderComponent>(*this, "FreeSans.ttf",level, localeTag));
}

std::ostream& CenterText::print(std::ostream &out) {
	return out;
}

