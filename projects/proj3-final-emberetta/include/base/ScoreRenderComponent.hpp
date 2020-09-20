#ifndef BASE_TEXT_RENDER_COMPONENT
#define BASE_TEXT_RENDER_COMPONENT

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>
#include "managers/LocaleManager.hpp"
#include "platformance/Platformance.hpp"




//! \brief Handles rendering text to the screen.
class ScoreRenderComponent: public RenderComponent {
public:

    ScoreRenderComponent(GameObject & gameObject, const std::string &fontResPath, Level * level);
    
    virtual void render(SDL_Renderer * renderer) const override;

private:
    std::shared_ptr<SDL_Texture> m_texture;  
    Level * level;
	std::shared_ptr<TTF_Font> font;  
};

#endif
