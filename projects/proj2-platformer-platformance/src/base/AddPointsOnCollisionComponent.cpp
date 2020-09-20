#include "base/AddPointsOnCollisionComponent.hpp"
#include "base/Level.hpp"
#include <iostream>

//! \brief A component which makes an object increase the player's score count upon collision with that object.

AddPointsOnCollisionComponent::AddPointsOnCollisionComponent(GameObject & gameObject, int tag):
  GenericComponent(gameObject),
  mTag(tag)
{
}

void
AddPointsOnCollisionComponent::collision(Level & level, std::shared_ptr<GameObject> obj)
{
  if (obj->tag() == mTag) {
    level.incrementScore(10);
  }
}
