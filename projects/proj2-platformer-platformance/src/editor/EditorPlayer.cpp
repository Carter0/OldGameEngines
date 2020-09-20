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
	setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 255,0,0));
	addGenericCompenent(std::make_shared<FreelookInputComponent>(*this, 10.0f));
	addGenericCompenent(std::make_shared<CameraComponent>(*this));
	setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
}


