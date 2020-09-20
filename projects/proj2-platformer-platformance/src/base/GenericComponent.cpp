#include "base/GenericComponent.hpp"

//! \brief A class to represent a generic component for GameObjects.
GenericComponent::GenericComponent(GameObject & gameObject):
  Component(gameObject)
{
}

void
GenericComponent::update(Level & level)
{
}

void
GenericComponent::collision(Level & level, std::shared_ptr<GameObject> obj)
{
}
