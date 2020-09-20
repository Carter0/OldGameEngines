#include "base/LivesRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>

//! \brief A component which renders text on the screen.
LivesRenderComponent::LivesRenderComponent(GameObject & gameObject, const std::string &fontResPath, Level* level):
  RenderComponent(gameObject),
  level(level) 
  {
	font = ResourceManager::getInstance().loadFont(fontResPath);
	if (font == nullptr) {
		std::cout << "TTF_OpenFont" << " error: " << SDL_GetError() << std::endl;
	}
  }

void
LivesRenderComponent::render(SDL_Renderer * renderer) const
{
    char livesBuffer[10];
	sprintf(livesBuffer, "%s %d", LocaleManager::getInstance().getText(LIVES).c_str(), level->m_lives);
		
	//The SDL surface needed for our lives and score text
	SDL_Color color = { 255, 255, 255, 255 };
	std::shared_ptr < SDL_Surface > livesSurface = create_shared(TTF_RenderUTF8_Blended(font.get(), livesBuffer, color));

	if (livesSurface == nullptr) {
		std::cout << "TTF_RenderText" << " error: " << SDL_GetError() << std::endl;
	}

	std::shared_ptr < SDL_Texture > livesTexture = create_shared(SDL_CreateTextureFromSurface(renderer, livesSurface.get()));
	if (livesTexture == nullptr) {
		std::cout << "CreateTexture" << " error: " << SDL_GetError() << std::endl;
	}

	//Get information about how long our text is going to be.
	int wLives, hLives;
	SDL_QueryTexture(livesTexture.get(), NULL, NULL, &wLives, &hLives);

	// Set where the score will be on the screen.
	int x2 = wLives - 100;
	SDL_Rect livesRect = { x2, 50, wLives, hLives };

	SDL_RenderCopy(renderer, livesTexture.get(), NULL, &livesRect);
}
