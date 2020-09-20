/*
 * GameObject.hpp
 *
 *  Created on: Jan 31, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_GAMEOBJECT_HPP_
#define INCLUDE_GAMEOBJECT_HPP_

#include <SDL.h>
#include <ostream>

struct BoundingBox {
	BoundingBox() = default;

	BoundingBox(int a, int b, int c, int d) {
		x = a;
		y = b;
		w = c;
		h = d;
	}
	int x,y,w,h;
};


inline std::ostream& operator<< (std::ostream &out, BoundingBox const& data) {
    out << "(" << data.x << "," << data.y << "," << data.w << "," << data.h << ")";
    return out;
}

/**
 * The superclass which organizes all of the necessary objects in the game. Currently, it is a pure virtual class.
 */
class GameObject {
public:
	/**
	 * A method which updates the GameObject, usually based on how it is intended to change each frame.
	 */
	virtual void update() = 0;
	/**
	 * Draws this GameObject on the screen, using a specified renderer.
	 *
	 * @param renderer The renderer which will be used to draw this GameObject
	 */
	virtual void render(SDL_Renderer * renderer) = 0;

	/**
	 * Provides the position of this GameObject, often used for collision detection purposes.
	 *
	 * @return A BoundingBox representing this GameObject's current position
	 */
	virtual BoundingBox getPosition() = 0;

	virtual ~GameObject() {}
};

#endif /* INCLUDE_GAMEOBJECT_HPP_ */
