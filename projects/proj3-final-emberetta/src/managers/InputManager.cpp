#include "managers/InputManager.hpp"
#include <algorithm>
#include <iostream>

InputManager&
InputManager::getInstance() {
	static InputManager *instance = new InputManager();
	return *instance;
}

void InputManager::startUp() { }

void InputManager::shutDown() { }

void InputManager::resetForFrame() {
	mKeysPressed.clear();
}

void InputManager::handleEvent(const SDL_Event &e) {
	SDL_GetMouseState(&mouseX, &mouseY);
	switch (e.type) {
	case SDL_KEYDOWN: {
		auto elem = mKeysDown.find(e.key.keysym.sym);
		if (elem == mKeysDown.end()) {
			mKeysPressed.insert(e.key.keysym.sym);
		}
		mKeysDown.insert(e.key.keysym.sym);
		break;
	}
	case SDL_KEYUP:
		mKeysDown.erase(e.key.keysym.sym);
		break;
	case SDL_MOUSEBUTTONDOWN:
		//SDL_GetMouseState(&mouseX, &mouseY);
		leftB = (e.button.button == SDL_BUTTON_LEFT);
		rightB = (e.button.button == SDL_BUTTON_RIGHT);
		std::cout << "MouseDown" << std::endl;
		break;
	case SDL_MOUSEBUTTONUP:
		//SDL_GetMouseState(&mouseX, &mouseY);
		if (leftB) {
			leftBClicked = (e.button.button == SDL_BUTTON_LEFT);
			leftB = false;
			std::cout << "LeftClick at " << getMousePos() << std::endl;
		}
		if (rightB) {
			rightBClicked = (e.button.button == SDL_BUTTON_RIGHT);
			rightB = false;
			std::cout << "RightClick at " << getMousePos() << std::endl;
		}
		break;
	}
}

bool InputManager::isKeyDown(SDL_Keycode k) const {
	return mKeysDown.find(k) != mKeysDown.end();
}

bool InputManager::isKeyPressed(SDL_Keycode k) const {
	return mKeysPressed.find(k) != mKeysPressed.end();
}
