#ifndef BASE_SOUND_ON_COLLIDE_COMPONENT
#define BASE_SOUND_ON_COLLIDE_COMPONENT

#include "base/GenericComponent.hpp"
#include <string>

//! \brief A component that plays a sound upon collision with another game object
class SoundOnCollideComponent: public GenericComponent {
public:

  SoundOnCollideComponent(GameObject & gameObject, int tag, std::string sound);
  
  virtual void collision(Level & level, std::shared_ptr<GameObject> obj) override;

private:

  int mTag;
  std::string m_sound;
  
};

#endif
