#pragma once
#ifndef LIVES_RENDER_COMPONENT
#define LIVES_RENDER_COMPONENT

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>
#include "managers/LocaleManager.hpp"
#include "breakout/Breakout.hpp"


//! \brief Handles rendering the lives to the screen for breakout
class LivesRenderComponent: public RenderComponent {
public:

    LivesRenderComponent(GameObject & gameObject, const std::string &fontResPath, Level * level);
    
    virtual void render(SDL_Renderer * renderer) const override;

private:
    std::shared_ptr<SDL_Texture> m_texture;  
	std::shared_ptr<TTF_Font> font;  
    Level * level;
};

#endif
