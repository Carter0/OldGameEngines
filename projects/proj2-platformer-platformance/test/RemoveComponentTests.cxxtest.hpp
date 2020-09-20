#include <cxxtest/TestSuite.h>
#include "platformance/objects/Player.hpp"
#include "platformance/objects/Coin.hpp"
#include "base/Level.hpp"

#define PI 3.14159265359

class RemoveTestSuite: public CxxTest::TestSuite
{
public:

	const float EPSILON = 0.001f;

	void testRemoveWorking() {
		{
			Level l(200,200);
			std::shared_ptr<Coin> c = std::make_shared<Coin>(0,0,10,10);
			std::shared_ptr<Player> p = std::make_shared<Player>(0,0,10,10);

			TS_ASSERT(l.objects().size() == 2);

			p->collision(l, c);
			l.update();
			TS_ASSERT(l.objects().size() == 1);
		}
	}


};

