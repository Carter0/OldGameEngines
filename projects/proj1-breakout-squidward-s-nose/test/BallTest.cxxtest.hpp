/*
 * BallTest.cxxtest.hpp
 *
 *  Created on: Feb 13, 2020
 *      Author: Red
 */

#ifndef TEST_BALLTEST_CXXTEST_HPP_
#define TEST_BALLTEST_CXXTEST_HPP_

#include "Ball.hpp"
#include <cxxtest/TestSuite.h>

class BallTest : public CxxTest::TestSuite
{
	Ball testBall = Ball();
	BoundingBox testBox1 = BoundingBox(645, 534, 3, 4); //numbers are so specific because it's set up for a bounce call
	BoundingBox testBox2 = BoundingBox(644, 535, 3, 4); //numbers are so specific because it's set up for a bounce call

	public:
	void testBallPosition(void)
	{
		testBall.reset();
		TS_ASSERT(testBall.getRadius() == 10);
		TS_ASSERT(testBall.getDirection().x == 1 && testBall.getDirection().y == -1);
		TS_ASSERT(testBall.getPosition().x == 640 && testBall.getPosition().y == 540);
		testBall.update();
		TS_ASSERT(testBall.getDirection().x == 1 && testBall.getDirection().y == -1); //direction should stay the same because it hasn't bounced
		TS_ASSERT(testBall.getPosition().x == 645 && testBall.getPosition().y == 535); //should be the new position after 1 update
		testBall.bounce(testBox1);
		TS_ASSERT(testBall.getDirection().x == -1 && testBall.getDirection().y == -1);
		testBall.bounce(testBox2);
		TS_ASSERT(testBall.getDirection().x == -1 && testBall.getDirection().y == 1);

	}
};


#endif /* TEST_BALLTEST_CXXTEST_HPP_ */
