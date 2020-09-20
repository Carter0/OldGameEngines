#include <cxxtest/TestSuite.h>
#include "platformance/objects/Player.hpp"
#include "platformance/objects/Coin.hpp"
#include "platformance/objects/Goal.hpp"
#include "base/Level.hpp"

#define PI 3.14159265359

class AddPointsTestSuite: public CxxTest::TestSuite
{
public:

	const float EPSILON = 0.001f;

	void testRemoveWorking() {
		{
			Level l(200,200);
			std::shared_ptr<Coin> c = std::make_shared<Coin>(0,0,10,10);
			std::shared_ptr<Player> p = std::make_shared<Player>(0,0,10,10);

			TS_ASSERT(l.m_score == 0);

			p->collision(l, c);
			std::cout << l.m_score << std::endl;
			TS_ASSERT(l.m_score == 10);
		}
	}


};
