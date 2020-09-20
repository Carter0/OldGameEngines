#include "base/LoseLifeComponent.hpp"
#include "base/Level.hpp"
#include <iostream>

LoseLifeComponent::LoseLifeComponent(GameObject & gameObject, int tag):
  GenericComponent(gameObject),
  mTag(tag) {}

void
LoseLifeComponent::collision(Level & level, std::shared_ptr<GameObject> obj)
{
  if (obj->tag() == mTag) {
    level.loseLife();
  }
}
