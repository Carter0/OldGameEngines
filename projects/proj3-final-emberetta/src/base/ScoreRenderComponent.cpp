#include "base/ScoreRenderComponent.hpp"
#include "base/GameObject.hpp"
#include "managers/ResourceManager.hpp"
#include <string>

//! \brief A component which renders text on the screen.
ScoreRenderComponent::ScoreRenderComponent(GameObject & gameObject, const std::string &fontResPath, Level* level):
  RenderComponent(gameObject),
  level(level) 
  {
	font = ResourceManager::getInstance().loadFont(fontResPath);
	if (font == nullptr) {
		std::cout << "TTF_OpenFont" << " error: " << SDL_GetError() << std::endl;
	}
  }

void
ScoreRenderComponent::render(SDL_Renderer * renderer) const
{
    char scoreBuffer[15];
	sprintf(scoreBuffer, "%s %d", LocaleManager::getInstance().getText(SCORE).c_str(), level->m_score);
		
	//The SDL surface needed for our lives and score text
	SDL_Color color = { 255, 255, 255, 255 };
	std::shared_ptr < SDL_Surface > scoreSurface = create_shared(TTF_RenderUTF8_Blended(font.get(), scoreBuffer, color));

	if (scoreSurface == nullptr) {
		std::cout << "TTF_RenderText" << " error: " << SDL_GetError() << std::endl;
	}

	std::shared_ptr < SDL_Texture > scoreTexture = create_shared(SDL_CreateTextureFromSurface(renderer, scoreSurface.get()));
	if (scoreTexture == nullptr) {
		std::cout << "CreateTexture" << " error: " << SDL_GetError() << std::endl;
	}

	//Get information about how long our text is going to be.
	int wScore, hScore;
	SDL_QueryTexture(scoreTexture.get(), NULL, NULL, &wScore, &hScore);

	// Set where the score will be on the screen.
	int x2 = (level->w() - wScore) - 50;
	SDL_Rect scoreRect = { x2, 50, wScore, hScore };

	SDL_RenderCopy(renderer, scoreTexture.get(), NULL, &scoreRect);
}
