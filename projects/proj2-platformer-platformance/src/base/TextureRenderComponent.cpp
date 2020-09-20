#include "base/TextureRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>

//! \brief A component which renders a specified texture on the screen.
TextureRenderComponent::TextureRenderComponent(GameObject &gameObject, std::string path, const SDL_Rect src) : RenderComponent(gameObject), m_src(src) {
	m_texture = ResourceManager::getInstance().loadTexture(path);
}

void TextureRenderComponent::render(SDL_Renderer *renderer) const {
	Vector2D offset = GameObject::getCameraOffset();
	SDL_Rect rect = { (int) (gameObject().x() - offset.x), (int) (gameObject().y() - offset.y), (int) gameObject().w(), (int) gameObject().h() };

	SDL_RenderCopyEx(renderer, m_texture.get(), &m_src, &rect, 0, NULL, SDL_FLIP_NONE);
}
