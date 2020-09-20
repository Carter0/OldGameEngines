/*
 * Platformance.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: jaked
 */

#include "platformance/PlatformanceEditor.hpp"
#include "managers/ResourceManager.hpp"

using namespace PlatformanceObjects;

PlatformanceEditor::PlatformanceEditor(int w, int h) : Platformance(w, h) { }

void PlatformanceEditor::update() {
	if (InputManager::getInstance().isKeyPressed(SDLK_r)) {
		loadLevel(m_level);
	} else if (InputManager::getInstance().isKeyPressed(SDLK_s)) {
		std::fstream fin;    //File pointer
		std::stringstream ss;
		ss << m_level << ".lvl";
		std::string path = getResourcePath(m_resAffix + "levels/");
		fin.open(path + ss.str(), std::ios::out | std::ios::trunc);//Open an existing file
		fin.clear();
		fin << print(fin);
		fin.close();
	} else if (InputManager::getInstance().isKeyPressed(SDLK_n)) {
		loadLevel(m_level + 1);
	}

	bool shift = false;
	if (InputManager::getInstance().isKeyPressed(SDLK_q)) {
		if (placing < PLACING_ENEMY) {
			placing++;
		} else {
			placing = PLACING_COIN;
		}
		shift = true;
	}

	if (InputManager::getInstance().isKeyPressed(SDLK_e)) {
		if (placing > PLACING_COIN) {
			placing--;
		} else {
			placing = PLACING_ENEMY;
		}
		shift = true;
	}
	if (shift) {
		blockCorner = endCorner = Vector2D(0, 0);
		if (placing == PLACING_COIN) {
			std::cout << "Placing coins. You can have as many of these as you want." << std::endl;
		} else if (placing == PLACING_PLAYER) {
			std::cout << "Placing the player. Placing one will delete the last one." << std::endl;
		} else if (placing == PLACING_BLOCK) {
			std::cout << "Placing blocks. Click and drag from one corner to any other." << std::endl;
		} else if (placing == PLACING_GOAL) {
			std::cout << "Placing the goal. Placing one will delete the last one." << std::endl;
		} else if (placing == PLACING_ENEMY) {
			std::cout << "Placing enemies. You can have as many of these as you want." << std::endl;
		}
		shift = false;
	}

	Level::update();

	if (InputManager::getInstance().isLeft()) {
		if (!blocking) {
			blockCorner = GameObject::getCameraOffset() + InputManager::getInstance().getMousePos();
		}
		endCorner = GameObject::getCameraOffset() + InputManager::getInstance().getMousePos();
		blocking = true;
	} else {
		if (blocking) {
			if (placing == PLACING_BLOCK) {
				float x, y, w, h;
				alterValues(x, y, w, h);
				addObject(std::make_shared < Brick > (x, y, w, h));
			} else {
				if (placing == PLACING_ENEMY) {
					addObject(std::make_shared < Enemy > (endCorner.x, endCorner.y, 21, 21));//The magic numbers below are the dimensions of the enemy. Perhaps this should be defined somewhere within Enemy, to avoid magic numbers?
				} else if (placing == PLACING_COIN) {
					addObject(std::make_shared < Coin > (endCorner.x, endCorner.y, 30, 30));//These magic numbers are the dimensions of the coin. Perhaps this should be defined somewhere within Coin, to avoid magic numbers?
				} else if (placing == PLACING_PLAYER) {
					for (auto gameObject : mObjects) {
						if (gameObject->typeCheck() == "Player") {
							removeObject(gameObject);
						}
					}
					addObject(std::make_shared < Player > (endCorner.x, endCorner.y, 30, 45));//These magic numbers are the dimensions of the coin. Perhaps this should be defined somewhere within Coin, to avoid magic numbers?
				} else if (placing == PLACING_GOAL) {
					for (auto gameObject : mObjects) {
						if (gameObject->typeCheck() == "Goal") {
							removeObject(gameObject);
						}
					}
					addObject(std::make_shared < Goal > (endCorner.x, endCorner.y, 50, 50, m_level+1));//These magic numbers are the dimensions of the coin. Perhaps this should be defined somewhere within Coin, to avoid magic numbers?
				}
				blockCorner = endCorner = Vector2D(0, 0);
			}
		}
		blocking = false;
	}

	if (InputManager::getInstance().isRight()) {
		Vector2D deleteHere = GameObject::getCameraOffset() + InputManager::getInstance().getMousePos();
		for (auto gameObject : mObjects) {
			if (gameObject->tag() == TAG_BACKGROUND || gameObject->tag() == PlatformanceObjects::TAG_GAMECONTROLLER ) {
				continue;
			}
			if (gameObject->x() <= deleteHere.x && deleteHere.x <= gameObject->x() + gameObject->w() && gameObject->y() <= deleteHere.y && deleteHere.y <= gameObject->y() + gameObject->h()) {
				removeObject(gameObject);
				break;
			}
		}
		blockCorner = endCorner = Vector2D(0, 0);
	}
}

void PlatformanceEditor::render(SDL_Renderer *renderer) {
	for (auto gameObject : mObjects) {
		gameObject->render(renderer);
	}

	if (blockCorner.x != endCorner.x && endCorner.x != endCorner.y) {//Lots of repeated code here. Maybe there's a way to trim it down? Abstract it out?
		Vector2D offset = GameObject::getCameraOffset();
		SDL_Rect rect, src;
		std::shared_ptr < SDL_Texture > tex;
		if (placing == PLACING_BLOCK) {
			float x, y, w, h;
			alterValues(x, y, w, h);
			rect = { (int) (x - offset.x), (int) (y - offset.y), (int) w, (int) h };
			src = { 0, 0, 32, 32 };
			tex = ResourceManager::getInstance().loadTexture("brick.png");
		} else if (placing == PLACING_ENEMY) {
			rect = { (int) (endCorner.x - offset.x), (int) (endCorner.y - offset.y), 21, 21 };//Same issue as above
			src = { 0, 0, 25, 26 };//Same issue as above
			tex = ResourceManager::getInstance().loadTexture("bee_spritesheet.png");
		} else if (placing == PLACING_COIN) {
			rect = { (int) (endCorner.x - offset.x), (int) (endCorner.y - offset.y), 30, 30 };//Same issue as above
			src = { 0, 0, 563, 564 };//Same issue as above
			tex = ResourceManager::getInstance().loadTexture("Gold_1.png");
		} else if (placing == PLACING_PLAYER) {
			rect = { (int) (endCorner.x - offset.x), (int) (endCorner.y - offset.y), 30, 45 };//Same issue as above
			src = { 0, 0, 30, 40 };//Same issue as above
			tex = ResourceManager::getInstance().loadTexture("adventurer-Sheet.png");
		} else if (placing == PLACING_GOAL) {
			rect = { (int) (endCorner.x - offset.x), (int) (endCorner.y - offset.y), 50, 50 };//Same issue as above
			src = { 82, 69, 92, 118 };//Same issue as above
			tex = ResourceManager::getInstance().loadTexture("flag.png");
		}
		SDL_RenderCopyEx(renderer, tex.get(), &src, &rect, 0, NULL, SDL_FLIP_NONE);
	}
}

void PlatformanceEditor::alterValues(float &x, float &y, float &w, float &h) {
	x = blockCorner.x;
	y = blockCorner.y;
	w = endCorner.x - blockCorner.x;
	h = endCorner.y - blockCorner.y;
	if (w < 0) {
		w = -w;
		x -= w;
	}
	if (h < 0) {
		h = -h;
		y -= h;
	}
}

void PlatformanceEditor::clear() {
	mObjects.clear();
	mObjectsToAdd.clear();
	mObjectsToRemove.clear();
}

void PlatformanceEditor::loadLevel(int level) {
	clear();
	blockCorner = endCorner = Vector2D(0, 0);
	m_level = level;
	ResourceManager::getInstance().loadLevel(this, level);
}

