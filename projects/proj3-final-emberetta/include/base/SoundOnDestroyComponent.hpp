/*
 * SoundOnDestroy.hpp
 *
 *  Created on: Apr 14, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_BASE_SOUNDONDESTROY_HPP_
#define INCLUDE_BASE_SOUNDONDESTROY_HPP_

#include "base/GenericComponent.hpp"
#include <string>

//! \brief A component that plays a sound upon collision with another game object
class SoundOnDestroyComponent: public GenericComponent {
public:

  SoundOnDestroyComponent(GameObject & gameObject, std::string sound);

  virtual void onDestroy(Level & level) override;

private:

  std::string m_sound;

};

#endif /* INCLUDE_BASE_SOUNDONDESTROY_HPP_ */
