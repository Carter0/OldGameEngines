/*
 * SoundOnDestroyComponent.cpp
 *
 *  Created on: Apr 14, 2020
 *      Author: jaked
 */

#include "base/SoundOnDestroyComponent.hpp"
#include "managers/AudioManager.hpp"

//! \brief A component that will make a GameObject play a sound upon colliding with another, specified GameObject.
SoundOnDestroyComponent::SoundOnDestroyComponent(GameObject & gameObject, std::string sound):
  GenericComponent(gameObject),
  m_sound(sound)
{
}

void
SoundOnDestroyComponent::onDestroy(Level & level)
{
    AudioManager::getInstance().playSound(m_sound);
}



