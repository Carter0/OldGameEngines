#include "base/Level.hpp"
#include <algorithm>
#include <iostream>
#include "managers/ResourceManager.hpp"

//! \brief A class to represent a level within the game.
Level::Level(int w, int h) : mW(w), mH(h), m_levelSize(w, h), m_score(0) {}

void Level::addObject(std::shared_ptr<GameObject> object) {
	mObjectsToAdd.push_back(object);
}

void Level::removeObject(std::shared_ptr<GameObject> object) {
	mObjectsToRemove.push_back(object);
}
void Level::removeObjectSilent(std::shared_ptr<GameObject> object) {
	mObjectsToRemoveSilent.push_back(object);
}

bool Level::hasObject(std::shared_ptr<GameObject> object) const {
  return std::find(mObjects.begin(), mObjects.end(), object) != mObjects.end();
}

void Level::incrementScore(const int score) {
	m_score += score;
}

void Level::loseLife() {
	m_lives -= 1;
}

bool Level::getCollisions(const GameObject &obj, std::vector<std::shared_ptr<GameObject>> &objects) const {
	objects.clear();
	for (auto gameObject : mObjects) {
		if (gameObject.get() != &obj && gameObject->isColliding(obj)) {
			objects.push_back(gameObject);
		}
	}
	return !objects.empty();
}

bool Level::getCollisions(float px, float py, std::vector<std::shared_ptr<GameObject>> &objects) const {
	objects.clear();
	for (auto gameObject : mObjects) {
		if (gameObject->isColliding(px, py)) {
			objects.push_back(gameObject);
		}
	}
	return !objects.empty();
}

void Level::update() {

	for (auto obj : mObjectsToAdd) {
		mObjects.push_back(obj);
	}
	mObjectsToAdd.clear();

	for (auto gameObject : mObjects) {
		gameObject->update(*this);
	}
	for (auto gameObject : mObjects) {
		gameObject->step(*this);
	}

	for (auto obj : mObjectsToRemove) {
		auto elem = std::find(mObjects.begin(), mObjects.end(), obj);
		if (elem != mObjects.end()) {
			obj->onDestroy(*this);
			mObjects.erase(elem);
		}
	}
	for (auto obj : mObjectsToRemoveSilent) {
		auto elem = std::find(mObjects.begin(), mObjects.end(), obj);
		if (elem != mObjects.end()) {
			mObjects.erase(elem);
		}
	}
	mObjectsToRemove.clear();
	mObjectsToRemoveSilent.clear();
}

void Level::render(SDL_Renderer *renderer) {
	for (auto gameObject : mObjects) {
		gameObject->render(renderer);
	}
}

std::string Level::print(std::ostream &out) {
	std::stringstream ss;
	out << "0 " << m_levelSize.x << " " << m_levelSize.y << std::endl;
	out << "1 " << m_music << std::endl;
	for (auto obj : mObjects) {
		obj->print(out);
	}
	ss << out.rdbuf();
	return ss.str();
}

void Level::setMusic(std::string newMusic) {
	m_music = newMusic;
	AudioManager::getInstance().playMusic(m_music);
}
