   #ifndef BASE_TEXTURE_RENDER_COMPONENT
#define BASE_TEXTURE_RENDER_COMPONENT

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>

//! \brief Handles rendering a game object as a simple rectangle.
class TextureRenderComponent: public RenderComponent {
public:

	TextureRenderComponent(GameObject & gameObject, std::string path, const SDL_Rect src);
  
  virtual void render(SDL_Renderer * renderer) const override;

private:
  std::shared_ptr<SDL_Texture> m_texture;  
  SDL_Rect m_src;
};

#endif
