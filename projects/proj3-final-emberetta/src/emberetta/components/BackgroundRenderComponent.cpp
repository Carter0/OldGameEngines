/*
 * BackgroundRenderComponent.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */


#include "emberetta/components/BackgroundRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>

BackgroundRenderComponent::BackgroundRenderComponent(
		GameObject & gameObject, std::string path,const SDL_Rect src, float speed) :
		RenderComponent(gameObject),
		m_src(src) {
	m_speed = speed;
	m_texture = ResourceManager::getInstance().loadTexture(path);
	gameObject.physicsComponent()->setVy(speed);
}

void BackgroundRenderComponent::render(SDL_Renderer *renderer) const {
	SDL_Rect rect = { (int) gameObject().x(), (int) gameObject().y(), (int) gameObject().w(), (int) gameObject().h() };
	SDL_Rect rect2 = { (int)gameObject().x(), (int)(gameObject().y() - gameObject().h()), (int)gameObject().w(), (int)gameObject().h() };

	SDL_RenderCopyEx(renderer, m_texture.get(), &m_src, &rect, 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, m_texture.get(), &m_src, &rect2, 0, NULL, SDL_FLIP_NONE);

}

