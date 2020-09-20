#ifndef BASE_TEXT_RENDER_COMPONENT
#define BASE_TEXT_RENDER_COMPONENT

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>
#include "managers/LocaleManager.hpp"
#include "platformance/Platformance.hpp"




//! \brief Handles rendering text to the screen.
class TextRenderComponent: public RenderComponent {
public:

    TextRenderComponent(GameObject & gameObject, const std::string &fontResPath, Platformance * level);
    
    virtual void render(SDL_Renderer * renderer) const override;

private:
    std::shared_ptr<SDL_Texture> m_texture;  
    Platformance * level;
	std::shared_ptr<TTF_Font> font;  
};

#endif
