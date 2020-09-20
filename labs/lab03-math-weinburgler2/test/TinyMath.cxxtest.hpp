#include <cxxtest/TestSuite.h>
#include "TinyMath.hpp"

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

  void testVector3dMultiplication() {
    Vector3D v(3, 4, 5);
    TS_ASSERT_EQUALS(v *= 2, Vector3D(6, 8, 10));
    TS_ASSERT_EQUALS(v *= -5, Vector3D(-30, -40, -50));  
  }

  void testVector3dDivision() {
    Vector3D v(1, 4, 9);
    TS_ASSERT_EQUALS(v /= 2, Vector3D(0.5f, 2, 4.5f));
  }

  void testVector3dAddition() {
    Vector3D v(-1, -2, -3);
    TS_ASSERT_EQUALS(v += Vector3D(2, 2, 2), Vector3D(1, 0, -1));
  }

  void testVector3dSubtraction() {
    Vector3D v(-1, -2, -3);
    TS_ASSERT_EQUALS(v -= Vector3D(2, 2, 2), Vector3D(-3, -4, -5));
  }

  void testVector3dDotProduct() {
    {
      Vector3D v1(1, 2, 3);
      Vector3D v2(1, 5, 7);
      TS_ASSERT_EQUALS(Dot(v1, v2), 32.0f);
    }
    {
      Vector3D v1(-1, -2, 3);
      Vector3D v2(4, 0, -8);
      TS_ASSERT_EQUALS(Dot(v1, v2), -28.0f);
    }
  }

  void testVector3dMultiplication2() {
    Vector3D v(1, 2, 3);
    TS_ASSERT_EQUALS(v * 2, Vector3D(2, 4, 6));
  }

  void testVector3dDivision2() {
    Vector3D v(1, 2, 3);
    TS_ASSERT_EQUALS(v / 2, Vector3D(0.5f, 1.0f, 1.5f));
  }
  
  void testVector3dNegation() {
    Vector3D v(8, 13, 54);
    TS_ASSERT_EQUALS(- v, Vector3D(-8, -13, -54));
  }

  void testVectorMagnitude() {
    {
      Vector3D v(2, 4, -2);
      TS_ASSERT_DELTA(Magnitude(v), 4.89897949f, EPSILON);
    }
    {
      Vector3D v(1, 0, -3);
      TS_ASSERT_DELTA(Magnitude(v), 3.1622777f, EPSILON);
    }
  }

  void testVector3dAddition2() {
    TS_ASSERT_EQUALS(Vector3D(1, 0, -3) + Vector3D(2, 4, -2), Vector3D(3, 4, -5));
  }

  void testVector3dSubtraction2() {
    TS_ASSERT_EQUALS(Vector3D(1, 0, -3) - Vector3D(2, 4, -2), Vector3D(-1, -4, -1));
  }

  void testProjection() {
    Vector3D v1(1, 2, 3);
    Vector3D v2(2, 3, 4);
    Vector3D out = Project(v1, v2);
    TS_ASSERT_DELTA(out.x, 1.379f, EPSILON);
    TS_ASSERT_DELTA(out.y, 2.069f, EPSILON);
    TS_ASSERT_DELTA(out.z, 2.759f, EPSILON);
  }

  void testNormalize() {
    Vector3D v(2, -4, 1);
    Vector3D out = Normalize(v);
    TS_ASSERT_DELTA(out.x, 0.43643578f, EPSILON);
    TS_ASSERT_DELTA(out.y, -0.87287156f, EPSILON);
    TS_ASSERT_DELTA(out.z, 0.21821789f, EPSILON);
  }

  void testCrossProduct() {  
    Vector3D v1(1, -7, 1);
    Vector3D v2(5, 2, 4);
    Vector3D out = CrossProduct(v1, v2);
    TS_ASSERT_EQUALS(out.x, -30);
    TS_ASSERT_EQUALS(out.y, 1);
    TS_ASSERT_EQUALS(out.z, 37);   
  }


  void testMatrixMultiplication() {
      /*
    Matrix3D mat3d1(Vector3D(-1, 4, -6), Vector3D(8, 5, 16), Vector3D(2, 8, 5));
    Matrix3D mat3d2(Vector3D(12, 7, 6), Vector3D(8, 0, 5), Vector3D(3, 2, 4));
    Matrix3D out(Vector3D(-8, -14, -10), Vector3D(184, 88, 137), Vector3D(103, 24, 72));
    TS_ASSERT_EQUALS(mat3d1 * mat3d2, out);
     */
  }
 

  void testMatrixVectorMultiplication() {
    /*
    Vector3D v(3, 4, 3);
    Matrix3D mat3d(Vector3D(-1, 4, -6), Vector3D(8, 5, 16), Vector3D(2, 8, 5));
    Vector3D out(-5, 92, 53);
    TS_ASSERT_EQUALS(mat3d * v, out);
    */
  }



};
