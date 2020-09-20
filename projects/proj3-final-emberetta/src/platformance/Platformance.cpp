/*
 * Platformance.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: jaked
 */

#include "platformance/Platformance.hpp"
#include "managers/ResourceManager.hpp"

using namespace PlatformanceObjects;

Platformance::Platformance(int w, int h) : Level(w, h)  {
	m_max_level = MAX_LEVELS;
	m_resAffix = PLATFORMANCE_RESAFFIX;
}

void Platformance::update() {
	if (InputManager::getInstance().isKeyPressed(SDLK_r)) {
		loadLevel(m_level);
	} else if (InputManager::getInstance().isKeyPressed(SDLK_n)) {
		m_level++;
		m_level = m_level > MAX_LEVELS ? 1 : m_level;
		loadLevel(m_level);
	}
	if (m_stopped) {
		return;
	}

	Level::update();
}

void Platformance::render(SDL_Renderer *renderer) {
	for (auto gameObject : mObjects) {
		gameObject->render(renderer);
	}
}

void Platformance::clear() {
	mObjects.clear();
	mObjectsToAdd.clear();
	mObjectsToRemove.clear();
	m_stopped = false;
	m_score = 0;
}

void Platformance::loadLevel(int level) {
	if (level > m_max_level) {
		if (m_stopped) {
			return;
		}
		mObjectsToAdd.push_back(std::make_shared<YouWin>(this));
		m_stopped = true;
		Level::update();
		return;
	}
	clear();
	m_level = level;
	ResourceManager::getInstance().loadLevel(this, level);
}
