/*
 * emberetta.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_EMBERETTA_HPP_
#define INCLUDE_EMBERETTA_EMBERETTA_HPP_

#include "base/Level.hpp"
#include "managers/InputManager.hpp"
#include <iostream>
#include "StringMap.hpp"

namespace EmberettaObjects {
	const int MAX_LEVELS = 3;
	const std::string RESAFFIX = "emberetta/";
}

//! \brief A class representing the Emberetta game
class Emberetta: public Level {
public:
	Emberetta(int w, int h);
	virtual ~Emberetta() { };
	virtual void update() override;
	virtual void render(SDL_Renderer *renderer) override;
	void clear();
	virtual void loadLevel(int level = 1) override;
	void alterValues(float &x, float &y, float &w, float &h);
	//void renderEditor(SDL_Renderer* renderer);

protected:
	bool m_stopped {false};
	int time = 0;
	int timepassed = 0;

};



#endif /* INCLUDE_EMBERETTA_EMBERETTA_HPP_ */
