#include "breakout/Breakout.hpp"
#include "breakout/ObjectTypes.hpp"
#include "managers/ResourceManager.hpp"
#include "breakout/objects/YouLose.hpp"

using namespace BreakoutObjects;

Breakout::Breakout(int w, int h) : Level(w, h)  {
	m_lives = 3;
	m_max_level = MAX_LEVELS_BREAKOUT;
	m_resAffix = BREAKOUT_RESAFFIX;
}

void Breakout::update() {
	if (InputManager::getInstance().isKeyPressed(SDLK_r)) {
		loadLevel(m_level);
	} else if (InputManager::getInstance().isKeyPressed(SDLK_n)) {
		m_level = m_level == MAX_LEVELS ? 1 : m_level + 1;
		loadLevel(m_level);
	}

	if (m_stopped) {
		return;
	}

	balls = 0;
	bool noBlocks = mObjects.size() != 0 ? false : true;
	for (auto gameObject : mObjects) {
		if (gameObject->typeCheck() == "Block") {
			noBlocks = true;
		} else if (gameObject->typeCheck() == "Ball") {
			balls++;
		}
	}
	if (noBlocks == false) {
		loadLevel(m_level + 1);
	}

	if (m_lives <= 0) {
		mObjectsToAdd.push_back(std::make_shared<YouLose>(this));
		m_stopped = true;
	}

	Level::update();
}

void Breakout::render(SDL_Renderer *renderer) {
	for (auto gameObject : mObjects) {
		gameObject->render(renderer);
	}
}

void Breakout::clear() {
	mObjects.clear();
	mObjectsToAdd.clear();
	mObjectsToRemove.clear();
	m_stopped = false;
	m_score = 0;
}

void Breakout::loadLevel(int level) {
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
