/*
 * TextRenderComponent.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */



#include "base/TextRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>

//! \brief A component which renders text on the screen.
TextRenderComponent::TextRenderComponent(GameObject &gameObject, const std::string &fontResPath, Level *level, int localeTag) : RenderComponent(gameObject), level(level) {
	font = ResourceManager::getInstance().loadFont(fontResPath);
	if (font == nullptr) {
		std::cout << "TTF_OpenFont" << " error: " << SDL_GetError() << std::endl;
	}
	m_localeTag = localeTag;
}

void TextRenderComponent::render(SDL_Renderer *renderer) const {
	char textBuffer[20];
	sprintf(textBuffer, "%s", LocaleManager::getInstance().getText(m_localeTag).c_str());

	//The SDL surface needed for our lives and score text
	SDL_Color color = { 255, 255, 255, 255 };
	std::shared_ptr < SDL_Surface > textSurface = create_shared(TTF_RenderUTF8_Blended(font.get(), textBuffer, color));

	if (textSurface == nullptr) {
		std::cout << "TTF_RenderText" << " error: " << SDL_GetError() << std::endl;
	}

	std::shared_ptr < SDL_Texture > textTexture = create_shared(SDL_CreateTextureFromSurface(renderer, textSurface.get()));
	if (textTexture == nullptr) {
		std::cout << "CreateTexture" << " error: " << SDL_GetError() << std::endl;
	}

	//Get information about how long our text is going to be.
	int wText, hText;
	SDL_QueryTexture(textTexture.get(), NULL, NULL, &wText, &hText);

	// Set where the score will be on the screen.
	int x2 = level->w() / 2 - wText/2;
	int y2 = level->h() / 2 - hText;
	SDL_Rect scoreRect = { x2, y2, wText, hText };

	SDL_RenderCopy(renderer, textTexture.get(), NULL, &scoreRect);
}

