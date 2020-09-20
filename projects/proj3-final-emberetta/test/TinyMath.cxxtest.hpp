#include <cxxtest/TestSuite.h>
#include "TinyMath.hpp"

#define PI 3.14159265359

class TinyMathTestSuite: public CxxTest::TestSuite
{
public:

	const float EPSILON = 0.001f;

	void testVector3DElementAccess() {
		{
			Vector3D v;
			v[0] = 0.0;
			v[1] = 0.0;
			v[2] = 0.0;
			TS_ASSERT_DELTA(v[0], 0.0, EPSILON);
			TS_ASSERT_DELTA(v[1], 0.0, EPSILON);
			TS_ASSERT_DELTA(v[2], 0.0, EPSILON);

			const Vector3D & cv = v;
			TS_ASSERT_DELTA(cv[0], 0.0, EPSILON);
			TS_ASSERT_DELTA(cv[1], 0.0, EPSILON);
			TS_ASSERT_DELTA(cv[2], 0.0, EPSILON);
		}
		{
			Vector3D v;
			v[0] = 0.1;
			v[1] = 0.2;
			v[2] = 0.3;
			TS_ASSERT_DELTA(v[0], 0.1, EPSILON);
			TS_ASSERT_DELTA(v[1], 0.2, EPSILON);
			TS_ASSERT_DELTA(v[2], 0.3, EPSILON);

			const Vector3D & cv = v;
			TS_ASSERT_DELTA(cv[0], 0.1, EPSILON);
			TS_ASSERT_DELTA(cv[1], 0.2, EPSILON);
			TS_ASSERT_DELTA(cv[2], 0.3, EPSILON);
		}
		{
			Vector3D v;
			v[0] = -0.1;
			v[1] = -0.2;
			v[2] = -0.3;
			TS_ASSERT_DELTA(v[0], -0.1, EPSILON);
			TS_ASSERT_DELTA(v[1], -0.2, EPSILON);
			TS_ASSERT_DELTA(v[2], -0.3, EPSILON);

			const Vector3D & cv = v;
			TS_ASSERT_DELTA(cv[0], -0.1, EPSILON);
			TS_ASSERT_DELTA(cv[1], -0.2, EPSILON);
			TS_ASSERT_DELTA(cv[2], -0.3, EPSILON);
		}
	}
	void testV3dMult() {
		Vector3D a(1,2,3);
		float scal = .5;
		{
			Vector3D c(3,2,1);
			c *= scal;
			TS_ASSERT_DELTA(c[0], 1.5, EPSILON);
			TS_ASSERT_DELTA(c[1], 1, EPSILON);
			TS_ASSERT_DELTA(c[2], .5, EPSILON);
		}
		{
			Vector3D c = a * scal;
			TS_ASSERT_DELTA(c[0], .5, EPSILON);
			TS_ASSERT_DELTA(c[1], 1, EPSILON);
			TS_ASSERT_DELTA(c[2], 1.5, EPSILON);
		}

	}
	void testV3dDiv() {
		Vector3D a(1,2,3);
		float scal = .5;
		{
			Vector3D c(3,2,1);
			c /= scal;
			TS_ASSERT_DELTA(c[0], 6, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
			TS_ASSERT_DELTA(c[2], 2, EPSILON);
		}
		{
			Vector3D c = a / scal;
			TS_ASSERT_DELTA(c[0], 2, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
			TS_ASSERT_DELTA(c[2], 6, EPSILON);
		}
	}
	void testV3dPlus() {
		Vector3D a(1,2,3);
		Vector3D b(1,2,3);
		{
			Vector3D c(3,2,1);
			c += a;
			TS_ASSERT_DELTA(c[0], 4, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
			TS_ASSERT_DELTA(c[2], 4, EPSILON);
		}
		{
			Vector3D c = a + b;
			TS_ASSERT_DELTA(c[0], 2, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
			TS_ASSERT_DELTA(c[2], 6, EPSILON);
		}
	}
	void testV3dMinus() {
		Vector3D a(1,2,3);
		Vector3D b(1,2,3);
		{
			Vector3D c(3,2,1);
			c -= a;
			TS_ASSERT_DELTA(c[0], 2, EPSILON);
			TS_ASSERT_DELTA(c[1], 0, EPSILON);
			TS_ASSERT_DELTA(c[2], -2, EPSILON);
		}
		{
			Vector3D c = a - b;
			TS_ASSERT_DELTA(c[0], 0, EPSILON);
			TS_ASSERT_DELTA(c[1], 0, EPSILON);
			TS_ASSERT_DELTA(c[2], 0, EPSILON);
		}
	}
	void testV3dDot() {
		// 2 orthogonal vectors Dot product is 0
		{
			Vector3D a(1,0,0);
			Vector3D b(0,1,0);
			float c = Dot(a,b);
			TS_ASSERT_DELTA(c, 0, EPSILON);
		}
		{
			Vector3D a(1,2,3);
			Vector3D b(1,5,7);
			float c = Dot(a,b);
			TS_ASSERT_DELTA(c, 32, EPSILON);
		}

	}
	void testV3dProj() {
		{
			Vector3D a(1,0,3);
			Vector3D b(-1,4,2);
			Vector3D c = Project(a,b);
			TS_ASSERT_DELTA(c[0], .5, EPSILON);
			TS_ASSERT_DELTA(c[1], 0, EPSILON);
			TS_ASSERT_DELTA(c[2], 3.0/2.0, EPSILON);
		}
	}
	void testV3dMag() {
		{
			Vector3D a(1,0,3);
			float c = Magnitude(a);
			float sol = sqrt(10);
			TS_ASSERT_DELTA(c, sol, EPSILON);
		}
	}
	void testV3dNorm() {
		{
			Vector3D a(1,0,3);
			Vector3D c = Normalize(a);
			TS_ASSERT_DELTA(c[0], 1.0/sqrt(10), EPSILON);
			TS_ASSERT_DELTA(c[1], 0, EPSILON);
			TS_ASSERT_DELTA(c[2], 3.0/sqrt(10), EPSILON);
		}


	}
	void testV3dCross() {
		// Produce an orthogonal vector
		{
			Vector3D a(1,0,0);
			Vector3D b(0,1,0);
			Vector3D c = CrossProduct(a,b);
			TS_ASSERT_DELTA(c[0], 0, EPSILON)
			TS_ASSERT_DELTA(c[1], 0, EPSILON)
			TS_ASSERT_DELTA(c[2], 1, EPSILON)
		}
	}

	void testV2dMult() {
		Vector2D a(1,2);
		float scal = .5;
		{
			Vector2D c(3,2);
			c *= scal;
			TS_ASSERT_DELTA(c[0], 1.5, EPSILON);
			TS_ASSERT_DELTA(c[1], 1, EPSILON);
		}
		{
			Vector2D c = a * scal;
			TS_ASSERT_DELTA(c[0], .5, EPSILON);
			TS_ASSERT_DELTA(c[1], 1, EPSILON);
		}

	}
	void testV2dDiv() {
		Vector2D a(1,2);
		float scal = .5;
		{
			Vector2D c(3,2);
			c /= scal;
			TS_ASSERT_DELTA(c[0], 6, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
		}
		{
			Vector2D c = a / scal;
			TS_ASSERT_DELTA(c[0], 2, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
		}
	}
	void testV2dPlus() {
		Vector2D a(1,2);
		Vector2D b(1,2);
		{
			Vector2D c(3,2);
			c += a;
			TS_ASSERT_DELTA(c[0], 4, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
		}
		{
			Vector2D c = a + b;
			TS_ASSERT_DELTA(c[0], 2, EPSILON);
			TS_ASSERT_DELTA(c[1], 4, EPSILON);
		}
	}
	void testV2dMinus() {
		Vector2D a(1,2);
		Vector2D b(1,2);
		{
			Vector2D c(3,2);
			c -= a;
			TS_ASSERT_DELTA(c[0], 2, EPSILON);
			TS_ASSERT_DELTA(c[1], 0, EPSILON);
		}
		{
			Vector2D c = a - b;
			TS_ASSERT_DELTA(c[0], 0, EPSILON);
			TS_ASSERT_DELTA(c[1], 0, EPSILON);
			TS_ASSERT_DELTA(c[2], 0, EPSILON);
		}
	}
	void testV2dDot() {
		// 2 orthogonal vectors Dot product is 0
		{
			Vector2D a(1,0);
			Vector2D b(0,1);
			float c = Dot(a,b);
			TS_ASSERT_DELTA(c, 0, EPSILON);
		}
		{
			Vector2D a(1,2);
			Vector2D b(1,5);
			float c = Dot(a,b);
			TS_ASSERT_DELTA(c, 11, EPSILON);
		}

	}
	void testV2dProj() {
		{
			Vector2D a(1,2);
			Vector2D b(3,-8);
			Vector2D c = Project(a,b);
			TS_ASSERT_DELTA(c[0], -13.0/5, EPSILON);
			TS_ASSERT_DELTA(c[1], -26.0/5, EPSILON);
		}
	}
	void testV2dMag() {
		{
			Vector2D a(1,3);
			float c = Magnitude(a);
			float sol = sqrt(10);
			TS_ASSERT_DELTA(c, sol, EPSILON);
		}
	}
	void testV2dNorm() {
		{
			Vector2D a(1,3);
			Vector2D c = Normalize(a);
			TS_ASSERT_DELTA(c[0], 1.0/sqrt(10), EPSILON);
			TS_ASSERT_DELTA(c[1], 3.0/sqrt(10), EPSILON);
		}
	}


	void testMat3DIdent() {
		Matrix3D c = Matrix3D::identity();
		TS_ASSERT_DELTA(c[0][0], 1, EPSILON);
		TS_ASSERT_DELTA(c[0][1], 0, EPSILON);
		TS_ASSERT_DELTA(c[0][2], 0, EPSILON);

		TS_ASSERT_DELTA(c[1][0], 0, EPSILON);
		TS_ASSERT_DELTA(c[1][1], 1, EPSILON);
		TS_ASSERT_DELTA(c[1][2], 0, EPSILON);

		TS_ASSERT_DELTA(c[2][0], 0, EPSILON);
		TS_ASSERT_DELTA(c[2][1], 0, EPSILON);
		TS_ASSERT_DELTA(c[2][2], 1, EPSILON);
	}
	void testMat3DMult() {
		Matrix3D a(1,2,3,4,5,6,7,8,9);
		Matrix3D b(9,8,7,6,5,4,3,2,1);
		Matrix3D c = a*b;
		TS_ASSERT_DELTA(c[0][0], 30, EPSILON);
		TS_ASSERT_DELTA(c[0][1], 24, EPSILON);
		TS_ASSERT_DELTA(c[0][2], 18, EPSILON);

		TS_ASSERT_DELTA(c[1][0], 84, EPSILON);
		TS_ASSERT_DELTA(c[1][1], 69, EPSILON);
		TS_ASSERT_DELTA(c[1][2], 54, EPSILON);

		TS_ASSERT_DELTA(c[2][0], 138, EPSILON);
		TS_ASSERT_DELTA(c[2][1], 114, EPSILON);
		TS_ASSERT_DELTA(c[2][2], 90, EPSILON);
	}
	void testMat3DRotX() {
		Matrix3D c = Matrix3D::rotateX((45 * PI) / 180);
		TS_ASSERT_DELTA(c[0][0], 1, EPSILON);
		TS_ASSERT_DELTA(c[0][1], 0, EPSILON);
		TS_ASSERT_DELTA(c[0][2], 0, EPSILON);

		TS_ASSERT_DELTA(c[1][0], 0, EPSILON);
		TS_ASSERT_DELTA(c[1][1], .7071069, EPSILON);
		TS_ASSERT_DELTA(c[1][2], -.7071069, EPSILON);

		TS_ASSERT_DELTA(c[2][0], 0, EPSILON);
		TS_ASSERT_DELTA(c[2][1], .7071069, EPSILON);
		TS_ASSERT_DELTA(c[2][2], .7071069, EPSILON);
	}
	void testMat3DRotY() {
		Matrix3D c = Matrix3D::rotateY((30 * PI) / 180);
		TS_ASSERT_DELTA(c[0][0], .8660253, EPSILON);
		TS_ASSERT_DELTA(c[0][1], 0, EPSILON);
		TS_ASSERT_DELTA(c[0][2],.5000002, EPSILON);

		TS_ASSERT_DELTA(c[1][0], 0, EPSILON);
		TS_ASSERT_DELTA(c[1][1], 1, EPSILON);
		TS_ASSERT_DELTA(c[1][2], 0, EPSILON);

		TS_ASSERT_DELTA(c[2][0], -.5000002, EPSILON);
		TS_ASSERT_DELTA(c[2][1], 0, EPSILON);
		TS_ASSERT_DELTA(c[2][2], .8660253, EPSILON);
	}
	void testMat3DRotZ() {
		Matrix3D c = Matrix3D::rotateZ((60 * PI) / 180);
		TS_ASSERT_DELTA(c[0][0], .4999979, EPSILON);
		TS_ASSERT_DELTA(c[0][1], -.8660266, EPSILON);
		TS_ASSERT_DELTA(c[0][2], 0, EPSILON);

		TS_ASSERT_DELTA(c[1][0], .8660266, EPSILON);
		TS_ASSERT_DELTA(c[1][1], .4999979, EPSILON);
		TS_ASSERT_DELTA(c[1][2], 0, EPSILON);

		TS_ASSERT_DELTA(c[2][0], 0, EPSILON);
		TS_ASSERT_DELTA(c[2][1], 0, EPSILON);
		TS_ASSERT_DELTA(c[2][2], 1, EPSILON);
	}

};
