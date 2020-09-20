/*
 * ParallaxBackgroundTextureRenderer.hpp
 *
 *  Created on: Mar 23, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_PLATFORMANCE_COMPONENTS_PARALLAXBACKGROUNDTEXTURERENDERCOMPONENT_HPP_
#define INCLUDE_PLATFORMANCE_COMPONENTS_PARALLAXBACKGROUNDTEXTURERENDERCOMPONENT_HPP_
#include "base/RenderComponent.hpp"
#include <string>
#include <memory>
#include <SDL.h>

class ParallaxBackgroundTextureRenderComponent: public RenderComponent {
public:
	ParallaxBackgroundTextureRenderComponent(GameObject & gameObject, std::string path, const SDL_Rect src, float speed);

	virtual void render(SDL_Renderer * renderer) const override;

private:
	std::shared_ptr<SDL_Texture> m_texture;
	SDL_Rect m_src;
	float m_speed;
};



#endif /* INCLUDE_PLATFORMANCE_COMPONENTS_PARALLAXBACKGROUNDTEXTURERENDERCOMPONENT_HPP_ */
