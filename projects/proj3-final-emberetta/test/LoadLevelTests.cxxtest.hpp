#include <cxxtest/TestSuite.h>
#include "platformance/objects/Player.hpp"
#include "platformance/objects/Coin.hpp"
#include "platformance/objects/Goal.hpp"
#include "base/Level.hpp"

#define PI 3.14159265359

class LoadLevelTestSuite: public CxxTest::TestSuite
{
public:

	const float EPSILON = 0.001f;

	void testLoadLeveleWorking() {
		{
			Level l(200,200);
			std::shared_ptr<Goal> g = std::make_shared<Goal>(0,0,10,10,2);
			std::shared_ptr<Player> p = std::make_shared<Player>(0,0,10,10);
			l.addObject(g);
			l.addObject(p);

			TS_ASSERT(l.getLevel() == 1);
			g->collision(l, p);
			std::cout << l.getLevel() << std::endl;
			TS_ASSERT(l.getLevel() == 2);
		}
	}


};
