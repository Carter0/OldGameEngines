/*
 * ParallaxBackgroundTextureRenderComponent.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */
#include "platformance/components/ParallaxBackgroundTextureRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>

ParallaxBackgroundTextureRenderComponent::ParallaxBackgroundTextureRenderComponent(
		GameObject & gameObject, std::string path,const SDL_Rect src, float speed) :
		RenderComponent(gameObject),
		m_src(src) {
	m_speed = speed;
	m_texture = ResourceManager::getInstance().loadTexture(path);
}

void ParallaxBackgroundTextureRenderComponent::render(SDL_Renderer *renderer) const {
	Vector2D offset = GameObject::getCameraOffset();
	SDL_Rect rect = { (int) (gameObject().x() - offset.x * m_speed), (int) (gameObject().y()), (int) gameObject().w(), (int) gameObject().h() };
	SDL_Rect rect2 = { (int) (gameObject().x() - offset.x * m_speed) + (int) gameObject().w(), (int) (gameObject().y()), (int) gameObject().w(), (int) gameObject().h() };

	SDL_RenderCopyEx(renderer, m_texture.get(), &m_src, &rect, 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, m_texture.get(), &m_src, &rect2, 0, NULL, SDL_FLIP_NONE);
}
