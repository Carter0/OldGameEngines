/*
 * EditorPlayer.cpp
 *
 *  Created on: Mar 21, 2020
 *      Author: jaked
 */

#include "editor/EditorPlayer.hpp"
#include "editor/FreelookInputComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "platformance/components/CameraComponent.hpp"
#include "base/RectRenderComponent.hpp"

EditorPlayer::EditorPlayer(float x, float y, float w, float h): GameObject(x, y, w, h, TAG_EDITOR) {
	setRenderComponent(std::make_shared<RectRenderComponent>(*this, 255,0,0));
	addGenericComponent(std::make_shared<FreelookInputComponent>(*this, 10.0f));
	addGenericComponent(std::make_shared<CameraComponent>(*this));
	setPhysicsComponent(std::make_shared<PhysicsComponent>(*this, false));
}


