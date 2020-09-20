#include "emberetta/EmberettaEditor.hpp"

using namespace EmberettaObjects;

EmberettaEditor::EmberettaEditor(int w, int h) : Emberetta(w, h)  {
	m_lives = 3;
	m_max_level = EmberettaObjects::MAX_LEVELS;
	m_resAffix = EmberettaObjects::RESAFFIX;
}

void EmberettaEditor::update() {
	if (InputManager::getInstance().isKeyPressed(SDLK_r)) {
		loadLevel(m_level);
	} else if (InputManager::getInstance().isKeyPressed(SDLK_n)) {
		m_level = m_level > m_max_level - 1 ? 1 : m_level + 1;
		loadLevel(m_level);
	} else if (InputManager::getInstance().isKeyPressed(SDLK_p)) {
		m_stopped = !m_stopped;
	} else if (InputManager::getInstance().isKeyPressed(SDLK_s)) {
		std::fstream fin;    //File pointer
		std::stringstream ss;
		ss << m_level << ".lvl";
		std::string path = getResourcePath(m_resAffix + "levels/");
		fin.open(path + ss.str(), std::ios::out | std::ios::trunc);//Open an existing file
		fin.clear();
		fin << print(fin);
		fin.close();
	}

	if (InputManager::getInstance().isLeft()) {
			blocking = true;//this line is necessary to prevent doubling-up on spawner placing. Instead, it'll start placing the spawner on the next frame.
	} else {
		if (blocking) {
			int x, y, spd, del, max, type;
			std::cout << "Placing an enemy spawner. Please type its x-position.\n"
					"You may want to create this object offscreen--the room's x dimensions are between 0 and "
					<< Level::m_levelSize.x << "." << std::endl;
			std::cin >> x;
			std::cout << "Please type the spawner's y-position.\n"
					"You may want to create this object offscreen--the room's y dimensions are between 0 and "
					<< Level::m_levelSize.y << "." << std::endl;
			std::cin >> y;
			std::cout << "Please type however many frames you want to pass between enemy spawns. Minimum 1, though picking 1 will probably crash the game." << std::endl;
			std::cin >> spd;
			std::cout << "Please type however many frames you want to pass before this spawner activates. Minimum 0." << std::endl;
			std::cin >> del;
			std::cout << "Please type the maximum number of enemies you want this object to spawn before it shuts off. Minimum 1." << std::endl;
			std::cin >> max;
			std::cout << "The types of enemies this spawner can create are:\n0 -- Ship\n1 -- Fighter\n2 -- Bomber\n3 -- Interceptor\n"
					"Please type the number of one of them."<< std::endl;
			std::cin >> type;
			if (spd >= 1 && del >= 0 && max >= 1 && 0 <= type && type <= 3) {
				mObjects.push_back(std::make_shared < Spawner > (x, y, spd, del, max, type + 6));
				std::cout << "Spawner created." << std::endl;
			} else {
				std::cout << "One of the parameters was not valid. Nothing added." << std::endl;
			}
		}
		blocking = false;
	}

	if (InputManager::getInstance().isRight()) {
			unblocking = true;//this line is necessary to prevent doubling-up on spawner placing. Instead, it'll start placing the spawner on the next frame.
	} else {
		if (unblocking) {
			std::cout << "Deleting an enemy spawner. Enemy spawners are located at the following coordinates:" << std::endl;
			int counter = 0, deletee = 0;
			for (auto gameObject : mObjects) {
				if (gameObject->typeCheck() == "Spawner") {
					std::cout << counter++ << " -- " << gameObject->x() << ", " << gameObject->y() << std::endl;
				}
			}
			std::cout << std::endl << "Please type the number of the spawner you wish to delete." << std::endl;
			std::cin >> deletee;
			if (0 <= deletee && deletee <= counter) {
				counter = 0;
				for (auto gameObject : mObjects) {
					if (gameObject->typeCheck() == "Spawner") {
						if (counter == deletee) {
							removeObject(gameObject);
							std::cout << "Spawner deleted" << std::endl;
							break;
						} else {
							counter++;
						}
					}
				}
			} else {
				std::cout << "Invalid number. Try again." << std::endl;
			}

		}
		unblocking = false;
	}

	if(m_stopped) {//Add and remove objects without updating any object positions
		for (auto obj : mObjectsToAdd) {
			mObjects.push_back(obj);
			std::cout << "object added" << std::endl;
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
		Level::update();
	}
}

void EmberettaEditor::render(SDL_Renderer *renderer) {
	if (mRenderer != renderer) {
		mRenderer = renderer;
	}

	SDL_Rect fillRect;
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 127);
	for (auto gameObject : mObjects) {
		gameObject->render(renderer);
		if (gameObject->typeCheck() == "Spawner") {
			fillRect = { int(gameObject->x()), int(gameObject->y()), 32, 32 };
			SDL_RenderFillRect(renderer, &fillRect);
		}
	}
}

void EmberettaEditor::clear() {
	mObjects.clear();
	mObjectsToAdd.clear();
	mObjectsToRemove.clear();
	m_score = 0;
}

void EmberettaEditor::loadLevel(int level) {

	if (level > m_max_level) {
		if (m_stopped) {
			return;
		}
		//mObjectsToAdd.push_back(std::make_shared<YouWin>(this));
		m_stopped = true;
		Level::update();
		return;
	}
	clear();
	m_level = level;
	ResourceManager::getInstance().loadLevel(this, level);
	m_stopped = true;
}
