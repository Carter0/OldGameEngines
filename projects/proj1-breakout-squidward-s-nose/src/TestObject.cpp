/*
 * TestObject.cpp
 *
 *  Created on: Jan 31, 2020
 *      Author: jaked
 */

#include "TestObject.hpp"

void TestObject::update() {
	// Do nothing
}

void TestObject::render(SDL_Renderer * renderer){
	SDL_Rect fillRect = {x,y,w,h};
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
	SDL_RenderDrawRect(renderer, &fillRect);
}
BoundingBox TestObject::getPosition() {
	BoundingBox b;
	b.x = x;
	b.y = y;
	b.w = w;
	b.h = h;
	return b;
}


