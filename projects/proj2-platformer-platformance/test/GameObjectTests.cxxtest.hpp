#include <cxxtest/TestSuite.h>
#include "platformance/objects/Player.hpp"
#include "platformance/objects/Coin.hpp"
#include "base/Level.hpp"

#define PI 3.14159265359

class GameObjectsTestSuite: public CxxTest::TestSuite
{
public:

	const float EPSILON = 0.001f;

	void testCoords() {
		{
			Player p(0,0,10,10);
			TS_ASSERT(p.x() == 0);
			TS_ASSERT(p.y() == 0);
			TS_ASSERT(p.h() == 10);
			TS_ASSERT(p.w() == 10);
		}
	}
	void testSetCoordsX() {
		{
			Player p(0,0,10,10);
			TS_ASSERT(p.x() == 0);
			p.setX(53);
			TS_ASSERT(p.x() == 53);
		}
	}
	void testSetCoordsY() {
		{
			Player p(0,0,10,10);
			TS_ASSERT(p.y() == 0);
			p.setY(53);
			TS_ASSERT(p.y() == 53);
		}
	}
	void testSetCoordsW() {
		{
			Player p(0,0,10,10);
			TS_ASSERT(p.w() == 10);
			p.setW(53);
			TS_ASSERT(p.w() == 53);
		}
	}
	void testSetCoordsH() {
		{
			Player p(0,0,10,10);
			TS_ASSERT(p.h() == 10);
			p.setH(53);
			TS_ASSERT(p.h() == 53);
		}
	}


};
