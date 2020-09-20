/*
 * Emberetta.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#include "emberetta/Emberetta.hpp"
#include "emberetta/objects/PlayerWeaponsFactory.hpp"
#include "managers/ResourceManager.hpp"
#include "base/CenterText.hpp"

using namespace EmberettaObjects;

Emberetta::Emberetta(int w, int h) : Level(w, h)  {
	time = 1000;
	m_lives = 3;
	m_max_level = EmberettaObjects::MAX_LEVELS;
	m_resAffix = EmberettaObjects::RESAFFIX;
}

void Emberetta::update() {
	if (InputManager::getInstance().isKeyPressed(SDLK_r)) {
		PlayerWeaponsFactory::getInstance().reset();
		m_lives = 3;
		loadLevel(m_level);
	} else if (InputManager::getInstance().isKeyPressed(SDLK_n)) {
		PlayerWeaponsFactory::getInstance().reset();
		m_level = m_level > m_max_level - 1 ? 1 : m_level + 1;
		loadLevel(m_level);
	}
	if (m_stopped) {
		return;
	}

	if (m_lives <= 0) {
		m_stopped = true;
		mObjectsToAdd.push_back(std::make_shared<CenterText>(this,GAME_OVER));
		for (auto gameObject : mObjects) {
			if (gameObject->tag() == TAG_PLAYERSHIP) {
				removeObject(gameObject);
			}
		}

	}

	timepassed++;
	if (timepassed >= time) {
		m_level = m_level + 1;
		loadLevel(m_level);
	}

	Level::update();
}

void Emberetta::render(SDL_Renderer *renderer) {
	for (auto gameObject : mObjects) {
		gameObject->render(renderer);
	}
}

void Emberetta::clear() {
	mObjects.clear();
	mObjectsToAdd.clear();
	mObjectsToRemove.clear();
	m_stopped = false;
	m_score = 0;

}

void Emberetta::loadLevel(int level) {
	time = level * 1000;
	timepassed = 0;
	if (level > m_max_level) {
		if (m_stopped) {
			return;
		}
		mObjectsToAdd.push_back(std::make_shared<CenterText>(this,YOU_WIN));
		AudioManager::getInstance().playMusic("VictoryTune.ogg");
		m_stopped = true;
		Level::update();
		return;
	}
	clear();
	m_level = level;
	ResourceManager::getInstance().loadLevel(this, level);
}


