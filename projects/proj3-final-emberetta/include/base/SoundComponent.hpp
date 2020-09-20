#ifndef SOUND_COMPONENT
#define SOUND_COMPONENT

#include <string>
#include <memory>
#include <SDL.h>

//! \brief Handles Playing A Sound
class SoundComponent: public GenericComponent {
public:

    SoundComponent(GameObject & gameObject, std::string path);
  
    virtual void update(Level & level);

private:
     std::shared_ptr<Mix_Music> m_sound;
  
};

#endif