/*
 * WinRenderComponent.hpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_PLATFORMANCE_COMPONENTS_WINRENDERCOMPONENT_HPP_
#define INCLUDE_PLATFORMANCE_COMPONENTS_WINRENDERCOMPONENT_HPP_

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>
#include "managers/LocaleManager.hpp"
#include "platformance/Platformance.hpp"

//! \brief Handles rendering text to the screen.
class WinRenderComponent: public RenderComponent {
public:

    WinRenderComponent(GameObject & gameObject, const std::string &fontResPath, Level * level);

    virtual void render(SDL_Renderer * renderer) const override;

private:
    std::shared_ptr<SDL_Texture> m_texture;
    Level * level;
	std::shared_ptr<TTF_Font> font;
};



#endif /* INCLUDE_PLATFORMANCE_COMPONENTS_WINRENDERCOMPONENT_HPP_ */
