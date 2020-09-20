/*
 * EditorPlayer.hpp
 *
 *  Created on: Mar 21, 2020
 *      Author: jaked
 */

//! \brief

#ifndef INCLUDE_EDITOR_EDITORPLAYER_HPP_
#define INCLUDE_EDITOR_EDITORPLAYER_HPP_

#include <SDL.h>
#include "managers/ResourceManager.hpp"
#include "base/GameObject.hpp"
#include "Util.hpp"
#include "platformance/ObjectTypes.hpp"

/**
 * Represents an editor player, who does not interact with the world
 */
class EditorPlayer: public GameObject {
public:
	EditorPlayer(float x, float y, float w, float h);
};




#endif /* INCLUDE_EDITOR_EDITORPLAYER_HPP_ */
