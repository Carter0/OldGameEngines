
#include "base/LoseRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>

//! \brief A component which renders text on the screen.
LoseRenderComponent::LoseRenderComponent(GameObject &gameObject, const std::string &fontResPath, Level *level) : RenderComponent(gameObject), level(level) {
	font = ResourceManager::getInstance().loadFont(fontResPath);
	if (font == nullptr) {
		std::cout << "TTF_OpenFont" << " error: " << SDL_GetError() << std::endl;
	}
}

void LoseRenderComponent::render(SDL_Renderer *renderer) const {
	char loseBuffer[15];
	sprintf(loseBuffer, "%s", LocaleManager::getInstance().getText(GAME_OVER).c_str());

	//The SDL surface needed for our lives and score text
	SDL_Color color = { 255, 255, 255, 255 };
	std::shared_ptr < SDL_Surface > textSurface = create_shared(TTF_RenderUTF8_Blended(font.get(), loseBuffer, color));

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
	int x2 = level->w() / 2 - wText;
	int y2 = level->h() / 2 - hText;
	SDL_Rect loseRect = { x2, y2, wText, hText };

	SDL_RenderCopy(renderer, textTexture.get(), NULL, &loseRect);
}
