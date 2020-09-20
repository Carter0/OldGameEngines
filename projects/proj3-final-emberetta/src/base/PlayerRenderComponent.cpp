#include "base/PlayerRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>
#include <iostream>

//! \brief A component which renders a GameObject using the Player sprite.
PlayerRenderComponent::PlayerRenderComponent(GameObject & gameObject, const std::string& path):
  RenderComponent(gameObject)
{
	m_texture = ResourceManager::getInstance().loadTexture(path);
}

void
PlayerRenderComponent::render(SDL_Renderer * renderer) const
{

    std::shared_ptr<PhysicsComponent> physicsComponent = gameObject().physicsComponent();
	Vector2D offset = GameObject::getCameraOffset();

    //std::cout << "X velocity is: " << physicsComponent->vx() << std::endl;
    //std::cout << "Y velocity is: " << physicsComponent->vy() << std::endl;

    SDL_RendererFlip flip;
    if (physicsComponent->vx() < 0) {
        flip = SDL_FLIP_HORIZONTAL;
    } 
    else {
        flip = SDL_FLIP_NONE;
    }

    SDL_Rect src;
    if (physicsComponent->vy() < 0){
        // set the sprite to the jumping one in the spritesheet
        src = {122, 151, 13, 34};
    }else {
        // default sprite
        src = {14, 7, 19, 29};
    }
    

	SDL_Rect rect= {(int)(gameObject().x() - offset.x),
			(int)(gameObject().y() - offset.y),
			(int)gameObject().w(),
			(int)gameObject().h()};
	
	SDL_RenderCopyEx(renderer, m_texture.get(), &src, &rect, 0, NULL, flip);
}
