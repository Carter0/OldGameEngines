/*
 * YouWin.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#include "platformance/objects/YouWin.hpp"
#include "base/PhysicsComponent.hpp"
#include "platformance/components/WinRenderComponent.hpp"

YouWin::YouWin(Level * level): GameObject(0, 0, 0, 0, PlatformanceObjects::TAG_YOUWIN) {
    setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderComponent(std::make_shared<WinRenderComponent>(*this, "FreeSans.ttf", level));
}

std::ostream& YouWin::print(std::ostream &out) {
	return out;
}



