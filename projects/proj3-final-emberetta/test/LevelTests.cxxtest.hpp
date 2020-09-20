#include <cxxtest/TestSuite.h>
#include "platformance/objects/Player.hpp"
#include "platformance/objects/Coin.hpp"
#include "base/Level.hpp"

#define PI 3.14159265359

class LevelTestSuite: public CxxTest::TestSuite
{
public:

	const float EPSILON = 0.001f;

	void testScore() {
		{
			Level l(200,200);
			std::cout << l.m_score << std::endl;
			TS_ASSERT(l.m_score == 0);
		}
	}
	void testAddObject() {
		{
			Level l(200,200);
			TS_ASSERT(l.objects().size() == 0);
			l.addObject(std::make_shared<Player>(0,0,10,10));
			TS_ASSERT(l.objects().size() == 0);
			l.update();
			TS_ASSERT(l.objects().size() == 1);
		}
	}
	void testRemoveObject() {
		{
			Level l(200,200);
			std::shared_ptr<GameObject> obj = std::make_shared<Player>(0,0,10,10);
			l.addObject(obj);
			l.update();
			TS_ASSERT(l.objects().size() == 1);
			l.removeObject(obj);
			TS_ASSERT(l.objects().size() == 1);
			l.update();
			TS_ASSERT(l.objects().size() == 0);
		}
	}


};
