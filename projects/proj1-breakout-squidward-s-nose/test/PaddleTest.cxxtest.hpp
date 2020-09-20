/*
 * PaddleTest.cxxtest.hpp
 *
 *  Created on: Feb 13, 2020
 *      Author: Red
 */

#ifndef TEST_PADDLETEST_CXXTEST_HPP_
#define TEST_PADDLETEST_CXXTEST_HPP_

#include "Player.hpp"
#include <cxxtest/TestSuite.h>

class PlayerTest : public CxxTest::TestSuite
{
	PlayerPaddle testPlayer = PlayerPaddle();


	public:
	void testPaddle(void)
	{
		TS_ASSERT(testPlayer.getLives() == 3);
		testPlayer.loseLife();
		TS_ASSERT(testPlayer.getLives() == 2);
		TS_ASSERT(testPlayer.getPosition().x == 640);
		TS_ASSERT(testPlayer.getPosition().y == 600);
		TS_ASSERT(testPlayer.getPosition().w == 200);
		TS_ASSERT(testPlayer.getPosition().h == 40);
		testPlayer.update();
		TS_ASSERT(testPlayer.getPosition().x == 640); //should all be the same because the paddle has no velocity (yet)
		TS_ASSERT(testPlayer.getPosition().y == 600);
		TS_ASSERT(testPlayer.getPosition().w == 200);
		TS_ASSERT(testPlayer.getPosition().h == 40);
		testPlayer.setVelocity(1, true); //apply a BIG velocity of 1, and specify that it's going right
		testPlayer.update();
		TS_ASSERT(testPlayer.getPosition().x == 630); //massive change, i know
		TS_ASSERT(testPlayer.getPosition().y == 600); //should be the same because the paddle can't move up
		TS_ASSERT(testPlayer.getPosition().w == 200); //paddle shouldn't change size, should be same
		TS_ASSERT(testPlayer.getPosition().h == 40); // ^^
	}
};



#endif /* TEST_PADDLETEST_CXXTEST_HPP_ */
