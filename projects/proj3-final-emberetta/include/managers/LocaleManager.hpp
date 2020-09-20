/*
 * LocaleManager.hpp
 *
 *  Created on: Feb 17, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_LOCALEMANAGER_HPP_
#define INCLUDE_LOCALEMANAGER_HPP_

#include <string>
#include <vector>
#include "managers/ResourceManager.hpp"
#include "StringMap.hpp"


//! \brief Class for managing locales.
class LocaleManager {
private:

	LocaleManager(){}  // Private Singleton
	LocaleManager(LocaleManager const&) = delete; // Avoid copy constructor.
	void operator=(LocaleManager const&) = delete; // Don't allow copy assignment.
	LocaleManager(LocaleManager const&&) = delete; // Avoid move constructor.
	void operator=(LocaleManager const&&) = delete; // Don't allow move assignment.

	std::vector<std::string> text;

public:

	/**
	 * @return Instance of the LocaleManager
	 */
	static LocaleManager& getInstance()
	{
		static LocaleManager inst;
		return inst;
	}

	/**
	 * Equivalent to a constructor. Will start the SDL_Mixer
	 * @param path path to Locale file
	 * @return 0 on success
	 */
	inline int startUp(std::string path = ENGLISH_LOCALE) {
		text = ResourceManager::getInstance().loadLocale(path);
		return 0;
	}

	/**
	 * Closes the LocaleManager.
	 * 0 on success
	 */
	inline int shutDown() {
		text.clear();
		return 0;
	}

	/**
	 * Returns a localized string from the string map
	 * @param mapping int representing the string
	 * @return localized string
	 */
	inline std::string getText(int mapping) {
		return text[mapping];
	}

};
#endif /* INCLUDE_LOCALEMANAGER_HPP_ */
