#include <cxxtest/TestSuite.h>
#include "platformance/objects/Player.hpp"
#include "platformance/objects/Coin.hpp"
#include "base/Level.hpp"

#define PI 3.14159265359

class ATestSuite: public CxxTest::TestSuite
{
public:

	const float EPSILON = 0.001f;

	void testAddScoreWorking() {
		{
			Level l(200,200);

			int startScore = l.m_score;

			l.addObject(std::make_shared<Player>(0,0,10,10));
			l.addObject(std::make_shared<Coin>(-1,-1,10,10));

			l.update();

			int endScore = l.m_score;

			TS_ASSERT(startScore != endScore);
		}
	}


};
