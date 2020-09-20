#ifndef BASE_PLAYER_RENDER_COMPONENT
#define BASE_PLAYER_RENDER_COMPONENT

#include "base/RenderComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/GenericComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>

//! \brief Handles rendering of the player gameobject.
class PlayerRenderComponent: public RenderComponent {
public:

	PlayerRenderComponent(GameObject& gameObject, const std::string& path);
  
    virtual void render(SDL_Renderer* renderer) const override;

private:
  std::shared_ptr<SDL_Texture> m_texture; 
  std::shared_ptr<PhysicsComponent> physicsComponent; 
};

#endif