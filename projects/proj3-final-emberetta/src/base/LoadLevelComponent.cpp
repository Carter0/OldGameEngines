#include "base/LoadLevelComponent.hpp"
#include "base/Level.hpp"
#include <iostream>

//! \brief A class that is able to load a level component into the game.
LoadLevel::LoadLevel(GameObject & gameObject,int level, int tag):
    GenericComponent(gameObject),
    mTag(tag){
	m_level = level;
}

void
LoadLevel::collision(Level & level, std::shared_ptr<GameObject> obj)
{
    if (obj->tag() == mTag) {
    	std::cout << "Loading Level " << m_level << std::endl;
        level.loadLevel(m_level);
    }
}
