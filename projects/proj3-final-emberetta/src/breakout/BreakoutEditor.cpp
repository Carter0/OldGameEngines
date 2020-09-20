#include "breakout/BreakoutEditor.hpp"
#include "managers/ResourceManager.hpp"
#include <algorithm>

using namespace BreakoutObjects;

BreakoutEditor::BreakoutEditor(int w, int h) : Breakout(w, h) {}

void BreakoutEditor::update() {
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
	} else if (InputManager::getInstance().isKeyPressed(SDLK_SPACE)) {
		m_stopped = !m_stopped;
	}

	bool shift = false;
	if (InputManager::getInstance().isKeyPressed(SDLK_q)) {
		if (placing < PLACING_WALL) {
			placing++;
		} else {
			placing = PLACING_BLOCK;
		}
		shift = true;
	}

	if (InputManager::getInstance().isKeyPressed(SDLK_e)) {
		if (placing > PLACING_BLOCK) {
			placing--;
		} else {
			placing = PLACING_WALL;
		}
		shift = true;
	}
	if (shift) {
		blockCorner = endCorner = Vector2D(0, 0);
		if (placing == PLACING_BLOCK) {
			std::cout << "Placing blocks. These are destroyed on hit, and you can have as many of these as you want." << std::endl;
		} else if (placing == PLACING_PADDLE) {
			std::cout << "Placing a paddle. Keep in mind it can only move left or right." << std::endl;
		} else if (placing == PLACING_BALL) {
			std::cout << "Placing the ball. There can be multiple of these, but the more there are, the harder they are to juggle." << std::endl;
		} else if (placing == PLACING_WALL) {
			std::cout << "Placing a wall. These are unbreakable." << std::endl;
		}
		shift = false;
	}

	if (InputManager::getInstance().isLeft()) {
		if (!blocking) {
			blockCorner = GameObject::getCameraOffset() + InputManager::getInstance().getMousePos();
		}
		endCorner = GameObject::getCameraOffset() + InputManager::getInstance().getMousePos();
		blocking = true;
	} else {
		if (blocking) {
			if (placing != PLACING_BALL) {
				float x, y, w, h;
				alterValues(x, y, w, h);
				if (placing == PLACING_BLOCK) {
					addObject(std::make_shared < Block > (x, y, w, h));
				} else if (placing == PLACING_PADDLE) {
					addObject(std::make_shared < Paddle > (x, y, w, h));
				} else if (placing == PLACING_WALL) {
					addObject(std::make_shared < Wall > (x, y, w, h));
				}
			} else {
				if (placing == PLACING_BALL) {//The magic numbers below are the dimensions of the ball.
					addObject(std::make_shared < Ball > (endCorner.x, endCorner.y, 30, 30));
				}
			}
		}
		blockCorner = endCorner = Vector2D(0, 0);
		blocking = false;
	}

	if (InputManager::getInstance().isRight()) {
		Vector2D deleteHere = GameObject::getCameraOffset() + InputManager::getInstance().getMousePos();
		for (auto gameObject : mObjects) {
			if (gameObject->tag() == TAG_BACKGROUND || gameObject->tag() == PlatformanceObjects::TAG_GAMECONTROLLER ) {
				continue;
			}
			if (gameObject->x() <= deleteHere.x && deleteHere.x <= gameObject->x() + gameObject->w()
					&& gameObject->y() <= deleteHere.y && deleteHere.y <= gameObject->y() + gameObject->h()) {
				removeObject(gameObject);
				break;
			}
		}
		blockCorner = endCorner = Vector2D(0, 0);
	}

	if(m_stopped) {//Add and remove objects without updating any object positions
		for (auto obj : mObjectsToAdd) {
			mObjects.push_back(obj);
		}
		mObjectsToAdd.clear();
		for (auto obj : mObjectsToRemove) {
				auto elem = std::find(mObjects.begin(), mObjects.end(), obj);
			if (elem != mObjects.end()) {
				mObjects.erase(elem);
			}
		}
		mObjectsToRemove.clear();
	} else {
		balls = 0;
		bool noBlocks = false;
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
		Level::update();
	}
}

void BreakoutEditor::render(SDL_Renderer *renderer) {
	if (mRenderer != renderer) {
		mRenderer = renderer;
	}

	for (auto gameObject : mObjects) {
		gameObject->render(renderer);
	}

	if (blockCorner.x != endCorner.x && endCorner.x != endCorner.y) {
		float x, y, w, h;
		alterValues(x, y, w, h);
		SDL_Rect fillRect;
		if (placing != PLACING_BALL) {
			fillRect = { int(x), int(y), int(w), int(h) };
		} else {
			fillRect = { int(endCorner.x), int(endCorner.y), 30, 30 };//CHANGE THIS if the ball ever stops being a cube?
		}
		if (placing == PLACING_BLOCK) {
			SDL_SetRenderDrawColor(renderer, 200, 100, 200, 0xFF);
		} else if (placing == PLACING_WALL) {
			SDL_SetRenderDrawColor(renderer, 0, 150, 150, 0xFF);
		} else if (placing == PLACING_PADDLE) {
			SDL_SetRenderDrawColor(renderer, 102, 102, 255, 0xFF);
		} else if (placing == PLACING_BALL) {//CHANGE THIS if the ball ever stops being a cube?
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0xFF);
		}
		SDL_RenderFillRect(renderer, &fillRect);
	}
}

void BreakoutEditor::clear() {
	mObjects.clear();
	mObjectsToAdd.clear();
	mObjectsToRemove.clear();
	m_stopped = false;
	m_score = 0;
}

void BreakoutEditor::loadLevel(int level) {
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
	m_stopped = true;
	ResourceManager::getInstance().loadLevel(this, level);
}

void BreakoutEditor::alterValues(float &x, float &y, float &w, float &h) {
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
