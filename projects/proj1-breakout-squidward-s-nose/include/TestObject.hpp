/*
 * TestObject.hpp
 *
 *  Created on: Jan 31, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_TESTOBJECT_HPP_
#define INCLUDE_TESTOBJECT_HPP_

#include "GameObject.hpp"
#include "SDL.h"

class TestObject: public GameObject {
public:
	TestObject() = default;
	~TestObject(){}

	/**
	 * Updates this TestObject each frame. Currently, this method has no body, as TestObjects are merely used for
	 * testing purposes and therefore don't require an Update() function. However, the method exists for the purposes
	 * of inheritance, as being a GameObject is still necessary for TestObject.
	 */
	void update();
	/**
	 * Draws this TestObject on the screen.
	 *
	 * @param renderer The renderer which will be used to draw this TestObject.
	 */
	void render(SDL_Renderer * renderer);
	/**
	* Provides a BoundingBox which represents the TestObject's current position, for use with collision math.
	*
	* @return a BoundingBox representing this TestObject's current position
	*/
	BoundingBox getPosition();
private:
	int x{500};
	int y{450};
	int w{100};
	int h{100};

	int r{255};
	int g{0};
	int b{0};
};

#endif /* INCLUDE_TESTOBJECT_HPP_ */
