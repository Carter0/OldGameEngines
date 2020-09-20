/*
 * BackgroundRenderComponent.hpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_COMPONENTS_BACKGROUNDRENDERCOMPONENT_HPP_
#define INCLUDE_EMBERETTA_COMPONENTS_BACKGROUNDRENDERCOMPONENT_HPP_

#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>

class BackgroundRenderComponent: public RenderComponent {
public:
	BackgroundRenderComponent(GameObject & gameObject, std::string path, const SDL_Rect src, float speed);

	virtual void render(SDL_Renderer * renderer) const override;

private:
	std::shared_ptr<SDL_Texture> m_texture;
	SDL_Rect m_src;
	float m_speed;
};



#endif /* INCLUDE_EMBERETTA_COMPONENTS_BACKGROUNDRENDERCOMPONENT_HPP_ */
