#pragma once 

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>
#include "managers/LocaleManager.hpp"
#include "breakout/Breakout.hpp"

//! \brief Handles rendering the lose text to the screen.
class LoseRenderComponent: public RenderComponent {
public:

    LoseRenderComponent(GameObject & gameObject, const std::string &fontResPath, Level * level);
    virtual void render(SDL_Renderer * renderer) const override;

private:
    std::shared_ptr<SDL_Texture> m_texture;
    Level * level;
	std::shared_ptr<TTF_Font> font;
};



