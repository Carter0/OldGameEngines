#pragma once
#ifndef VECTOR2D_HPP_
#define VECTOR2D_HPP_

/*
 * Vector2D.hpp
 *
 *  Created on: Feb 2, 2020
 *  Author: Nicolas Karayakaylar
 */

/**
 * A simple class meant to represent a two-dimensional vector for use by numerous GameObjects and their functions.
 */
class Vector2D {
public:
	Vector2D() = default;

	Vector2D(float a, float b) {
		x = a;
		y = b;
	}

	/**
	 * Retrieves the X value of this Vector2D
	 *
	 * @return a Float representing the X value of this Vector2D
	 */
	float X() {
		return x;
	}

	/**
		 * Retrieves the y value of this Vector2D
		 *
		 * @return a Float representing the Y value of this Vector2D
		 */
	float Y() {
		return y;
	}

	float x, y;
};

#endif
