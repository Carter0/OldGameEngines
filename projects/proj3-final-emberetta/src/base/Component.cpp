#include "base/Component.hpp"

//! \brief The base class for all components in the game.

Component::Component(GameObject & gameObject):
  mGameObject(gameObject)
{
  (void) mGameObject; // to prevent warnings
}

Component::~Component()
{
}
