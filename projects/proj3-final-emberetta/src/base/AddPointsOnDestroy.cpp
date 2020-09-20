#include "base/AddPointsOnDestroy.hpp"
#include "base/Level.hpp"
#include <iostream>

//! \brief A component which makes an object increase the player's score count upon collision with that object.

AddPointsOnDestroy::AddPointsOnDestroy(GameObject & gameObject, unsigned int scoreToAdd):
  GenericComponent(gameObject),
  mScoreToAdd(scoreToAdd) {}

void AddPointsOnDestroy::onDestroy(Level & level) {
    level.incrementScore(mScoreToAdd);
}
