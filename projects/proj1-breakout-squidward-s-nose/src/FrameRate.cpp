/*
 * FrameRate.cpp
 *
 *  Created on: Jan 17, 2020
 *      Author: Jake Dec
 */

#include "FrameRate.hpp"

FrameRate::FrameRate(const std::string& path){
	lastTick = SDL_GetTicks();

	if (TTF_Init() != 0){
		SDL_Quit();
	}

	font = ResourceManager::getInstance().loadFont(path);
	if (font == nullptr){
		std::cout << "TTF_OpenFont" << " error: " << SDL_GetError() << std::endl;
	}
}

FrameRate::~FrameRate() {
	
}


void FrameRate::addTime() {
	times.push_back(SDL_GetTicks() - lastTick);
	lastTick = SDL_GetTicks();
	if (times.size() > frameCounts) {
		times.pop_front();
	}
}

// Gives Ticks since last addTime()
int FrameRate::sinceLast() {
	return SDL_GetTicks() - lastTick;
}

// Returns the average time of the last X frames
float FrameRate::averageTime() {
	int sum = 0;
	for ( int x : times )
		sum += x;
	return times.empty() ? 0 : (1000.0 / (1.0 * sum / times.size()));
}

void FrameRate::update(int screenWidth, int screenHeight, std::shared_ptr<SDL_Renderer> ren) {
	if (!visible)
		return;
	char buff[12];
	sprintf( buff, "%.3f", averageTime());
	// We need to first render to a surface as that's what TTF_RenderText
	// returns, then load that surface into a texture
	std::shared_ptr<SDL_Surface> surf = create_shared(TTF_RenderUTF8_Blended(font.get(), buff, color));
	if (surf == nullptr){
		std::cout << "TTF_RenderText" << " error: " << SDL_GetError() << std::endl;
	}
	std::shared_ptr<SDL_Texture> texture = create_shared(SDL_CreateTextureFromSurface(ren.get(), surf.get()));
	if (texture == nullptr){
		std::cout << "CreateTexture" << " error: " << SDL_GetError() << std::endl;
	}
	SDL_QueryTexture(texture.get(), NULL, NULL, &w, &h);
	x = screenWidth - w;
	y = screenHeight - h;
}

void FrameRate::render(std::shared_ptr<SDL_Renderer> ren) {
	if (!visible)
		return;
	SDL_Rect dst = {x,y,w,h};
	SDL_RenderCopy(ren.get(), texture.get(), NULL, &dst);
}
