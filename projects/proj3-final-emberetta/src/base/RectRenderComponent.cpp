#include "base/RectRenderComponent.hpp"
#include "base/GameObject.hpp"


//! \brief A component which renders a GameObject as a rectangle.
RectRenderComponent::RectRenderComponent(GameObject & gameObject, Uint8 r, Uint8 g, Uint8 b):
RenderComponent(gameObject),
mR(r),
mG(g),
mB(b)
{
}

void
RectRenderComponent::render(SDL_Renderer * renderer) const
{
	Vector2D cameraOffset = gameObject().getCameraOffset();
	int offSetX = int(gameObject().x()) - int(cameraOffset.x);
	int offSetY = int(gameObject().y()) - int(cameraOffset.y);
	SDL_Rect fillRect = { offSetX, offSetY, int(gameObject().w()), int(gameObject().h()) };
	SDL_SetRenderDrawColor(renderer, mR, mG, mB, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}
