#include "base/SoundOnCollideComponent.hpp"
#include "base/Level.hpp"
#include <iostream>

//! \brief A component that will make a GameObject play a sound upon colliding with another, specified GameObject.
SoundOnCollideComponent::SoundOnCollideComponent(GameObject & gameObject, int tag, std::string sound):
  GenericComponent(gameObject),
  mTag(tag),
  m_sound(sound)
{
}

void
SoundOnCollideComponent::collision(Level & level, std::shared_ptr<GameObject> obj)
{
  if (obj->tag() == mTag) {
    AudioManager::getInstance().playSound(m_sound);
  }
}
