/*
 * TextRenderComponent.hpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_BASE_TEXTRENDERCOMPONENT_HPP_
#define INCLUDE_BASE_TEXTRENDERCOMPONENT_HPP_

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>
#include "managers/LocaleManager.hpp"
#include "base/Level.hpp"

//! \brief Handles rendering text to the screen.
class TextRenderComponent: public RenderComponent {
public:

	TextRenderComponent(GameObject & gameObject, const std::string &fontResPath, Level * level, int localeTag);
    virtual void render(SDL_Renderer * renderer) const override;

private:
    std::shared_ptr<SDL_Texture> m_texture;
    Level * level;
	std::shared_ptr<TTF_Font> font;
	int m_localeTag;
};



#endif /* INCLUDE_BASE_TEXTRENDERCOMPONENT_HPP_ */
