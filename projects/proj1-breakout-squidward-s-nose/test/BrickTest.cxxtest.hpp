/*
 * BrickTest.cxxtest.hpp
 *
 *  Created on: Feb 13, 2020
 *      Author: Red
 */

#ifndef TEST_BRICKTEST_CXXTEST_HPP_
#define TEST_BRICKTEST_CXXTEST_HPP_


#include "Brick.hpp"
#include <cxxtest/TestSuite.h>

class BrickTest : public CxxTest::TestSuite
{
	BoundingBox testBox1 = BoundingBox(1, 2, 3, 4);
	BoundingBox testBox2 = BoundingBox(5, 6, 7, 8);
	Brick testBrick1 = Brick(testBox1, 1);


	public:
	void testSetSize(void)
	{
		testBrick1.setSize(testBox1);
		TS_ASSERT(testBrick1.getPosition().x == testBox1.x
				&& testBrick1.getPosition().y == testBox1.y
				&& testBrick1.getPosition().w == testBox1.w
				&& testBrick1.getPosition().h == testBox1.h);
		testBrick1.setSize(testBox2);
		TS_ASSERT(testBrick1.getPosition().x == testBox2.x
				&& testBrick1.getPosition().y == testBox2.y
				&& testBrick1.getPosition().w == testBox2.w
				&& testBrick1.getPosition().h == testBox2.h);
	}
};




#endif /* TEST_BRICKTEST_CXXTEST_HPP_ */
