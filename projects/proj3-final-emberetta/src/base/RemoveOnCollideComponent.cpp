#include "base/RemoveOnCollideComponent.hpp"
#include "base/Level.hpp"
#include <iostream>

//! \brief A component which will remove a GameObject when that GameObject collides with another, specified GameObject.
RemoveOnCollideComponent::RemoveOnCollideComponent(GameObject & gameObject, int tag):
  GenericComponent(gameObject),
  mTag(tag)
{
}

void
RemoveOnCollideComponent::collision(Level & level, std::shared_ptr<GameObject> obj)
{
  if (obj->tag() == mTag) {
    //std::cout << obj->tag() << std::endl;
    level.removeObject(obj);
  }
}
