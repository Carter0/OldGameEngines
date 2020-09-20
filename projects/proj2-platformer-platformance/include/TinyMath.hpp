// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#ifndef TINYMATH_HPP
#define TINYMATH_HPP

#include <cmath>
#include <iostream>

// Forward references of each of the structs
struct Vector3D;
struct Vector2D;
struct Matrix3D;

// Vector3D performs vector operations with 3-dimensions
// The purpose of this class is primarily for 3D graphics
// applications.
struct Vector3D{
	// Note: x,y,z are a convention
	// x,y,z could be position, but also any 3-component value.
	float x,y,z;

	// Default constructor
	// 'why default?' https://stackoverflow.com/questions/20828907/the-new-keyword-default-in-c11
	Vector3D() = default;

	// The "Real" constructor we want to use.
	// This initializes the values x,y,z
	Vector3D(float a, float b, float c){
		x = a;
		y = b;
		z = c;
	}

	// Index operator, allowing us to access the individual
	// x,y,z components of our vector.
	float& operator[](int i){
		return ((&x)[i]);
	}

	// Index operator, allowing us to access the individual
	// x,y,z components of our vector.
	const float& operator[](int i) const{
		return ((&x)[i]);
	}

	// Multiplication Operator
	// Multiply vector by a uniform-scalar.
	Vector3D& operator *=(float s){
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}

	// Division Operator
	Vector3D& operator /=(float s){
		x /= s;
		y /= s;
		z /= s;
		return (*this);
	}

	// Addition operator
	Vector3D& operator +=(const Vector3D& v){
		x += v.x;
		y += v.y;
		z += v.z;
		return (*this);
	}

	// Subtraction operator
	Vector3D& operator -=(const Vector3D& v){
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return (*this);
	}

};

// Compute the dot product of a Vector3D
inline float Dot(const Vector3D& a, const Vector3D& b){
	return a.x*b.x+a.y*b.y+a.z*b.z;;
}

// Multiplication of a vector by a scalar values
inline Vector3D operator *(const Vector3D& v, float s){
	Vector3D vec;
	vec.x = v.x * s;
	vec.y = v.y * s;
	vec.z = v.z * s;
	return vec;
}

// Division of a vector by a scalar value.
inline Vector3D operator /(const Vector3D& v, float s){
	Vector3D vec;
	vec.x = v.x / s;
	vec.y = v.y / s;
	vec.z = v.z / s;
	return vec;
}

// Negation of a vector
// Use Case: Sometimes it is handy to apply a force in an opposite direction
inline Vector3D operator -(const Vector3D& v){
	Vector3D vec = v*-1;
	return vec;
}

// Return the magnitude of a vector
inline float Magnitude(const Vector3D& v){
	return sqrt(v.x * v.x +
			v.y * v.y +
			v.z * v.z);
}

// Add two vectors together
inline Vector3D operator +(const Vector3D& a, const Vector3D& b){
	Vector3D vec;
	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return vec;
}

// Subtract two vectors
inline Vector3D operator -(const Vector3D& a, const Vector3D& b){
	Vector3D vec;
	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return vec;
}

// Vector Projection
inline Vector3D Project(const Vector3D& a, const Vector3D& b){
	return a*((float)Dot(a,b)/Dot(a,a));
}

// Set a vectors magnitude to 1
// Note: This is NOT generating a normal vector
inline Vector3D Normalize(const Vector3D& v){
	return v/Magnitude(v);
}

// a x b (read: 'a crossed b')
// Produces a new vector perpendicular to a and b.
// (So long as a and b are not parallel which returns zero vector)
inline Vector3D CrossProduct(const Vector3D& a, const Vector3D& b){
	Vector3D vec;
	vec.x = a.y * b.z - a.z * b.y;
	vec.y = a.z * b.x - a.x * b.z;
	vec.z = a.x * b.y - a.y * b.x;
	return vec;
}


// Vector2D performs vector operations with 2-dimensions
// The purpose of this class is primarily for 2D graphics
// applications.
struct Vector2D{
	// Note: x,y are a convention
	// x,y could be position, but also any 2-component value.
	float x,y;

	// Default constructor
	// 'why default?' https://stackoverflow.com/questions/20828907/the-new-keyword-default-in-c11
	Vector2D() = default;

	// The "Real" constructor we want to use.
	// This initializes the values x,y
	Vector2D(float a, float b){
		x = a;
		y = b;
	}

	// Index operator, allowing us to access the individual
	// x,y components of our vector.
	float& operator[](int i){
		return ((&x)[i]);
	}

	// Index operator, allowing us to access the individual
	// x,y components of our vector.
	const float& operator[](int i) const{
		return ((&x)[i]);
	}

	// Multiplication Operator
	// Multiply vector by a uniform-scalar.
	Vector2D& operator *=(float s){
		x *= s;
		y *= s;
		return (*this);
	}

	// Division Operator
	Vector2D& operator /=(float s){
		x /= s;
		y /= s;
		return (*this);
	}

	// Addition operator
	Vector2D& operator +=(const Vector2D& v){
		x += v.x;
		y += v.y;
		return (*this);
	}

	// Subtraction operator
	Vector2D& operator -=(const Vector2D& v){
		x -= v.x;
		y -= v.y;
		return (*this);
	}

};

inline std::ostream& operator << (std::ostream& o, const Vector2D& a)
{
    o << "(" << a.x << ", " << a.y << ")";
    return o;
}

// Compute the dot product of a Vector3D
inline float Dot(const Vector2D& a, const Vector2D& b){
	return a.x*b.x+a.y*b.y;
}

// Multiplication of a vector by a scalar values
inline Vector2D operator *(const Vector2D& v, float s){
	Vector2D vec;
	vec.x = v.x * s;
	vec.y = v.y * s;
	return vec;
}

// Division of a vector by a scalar value.
inline Vector2D operator /(const Vector2D& v, float s){
	Vector2D vec;
	vec.x = v.x / s;
	vec.y = v.y / s;
	return vec;
}

// Negation of a vector
// Use Case: Sometimes it is handy to apply a force in an opposite direction
inline Vector2D operator -(const Vector2D& v){
	Vector2D vec = v*-1;
	return vec;
}

// Return the magnitude of a vector
inline float Magnitude(const Vector2D& v){
	return sqrt(v.x * v.x +
			v.y * v.y);
}

// Add two vectors together
inline Vector2D operator +(const Vector2D& a, const Vector2D& b){
	Vector2D vec;
	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	return vec;
}

// Subtract two vectors
inline Vector2D operator -(const Vector2D& a, const Vector2D& b){
	Vector2D vec;
	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	return vec;
}

// Vector Projection (B onto A)
inline Vector2D Project(const Vector2D& a, const Vector2D& b){
	return a*(Dot(a,b)/Dot(a,a));
}

// Set a vectors magnitude to 1
// Note: This is NOT generating a normal vector
inline Vector2D Normalize(const Vector2D& v){
	return v/Magnitude(v);
}



// Matrix 3D represents 3x3 matrices in Math
struct Matrix3D{
private:
	float n[3][3];  // Store each value of the matrix

public:
	Matrix3D() = default;

	// TODO: Row or column major order you decide!
	// Matrix constructor with 9 scalar values.
	Matrix3D( float n00, float n01, float n02,
			float n10, float n11, float n12,
			float n20, float n21, float n22){

		n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
		n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
		n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
	}

	// Matrix constructor from three vectors.
	Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c){
		n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
		n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
		n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
	}

	// Index operator with two dimensions
	// Example: M(1,1) returns row 1 and column 1 of matrix M.
	float& operator ()(int i, int j){
		return (n[i][j]);
	}

	// Index operator with two dimensions
	// Example: M(1,1) returns row 1 and column 1 of matrix M.
	const float& operator ()(int i, int j) const{
		return (n[i][j]);
	}

	// Return a row from a matrix as a vector.
	Vector3D& operator [](int j){
		return (*reinterpret_cast<Vector3D *>(n[j]));
	}

	// Return a row from a matrix as a vector.
	const Vector3D& operator [](int j) const{
		return (*reinterpret_cast<const Vector3D *>(n[j]));
	}

	static Matrix3D identity() {
		return Matrix3D(1,0,0
				       ,0,1,0
					   ,0,0,1);
	}
	static Matrix3D rotateX(float rad) {
		return Matrix3D(1,0,0
				       ,0,cos(rad),-sin(rad)
					   ,0,sin(rad),cos(rad));
	}
	static Matrix3D rotateY(float rad) {
		return Matrix3D(cos(rad),0,sin(rad)
				       ,0,1,0
					   ,-sin(rad),0,cos(rad));
	}
	static Matrix3D rotateZ(float rad) {
		return Matrix3D(cos(rad),-sin(rad),0
				       ,sin(rad),cos(rad),0
					   ,0,0,1);
	}

};

// Matrix Multiplication
inline Matrix3D operator *(const Matrix3D& A, const Matrix3D& B){
	Matrix3D mat;
	mat[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0];
	mat[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1];
	mat[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2];
	mat[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0];
	mat[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1];
	mat[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2];
	mat[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0];
	mat[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1];
	mat[2][2] = A[2][0] * B[0][2] + A[2][1] * B[1][2] + A[2][2] * B[2][2];
	return mat;
}

// Matrix multiply by a vector

inline Vector3D operator *(const Matrix3D& M, const Vector3D& v){
	Vector3D vec;
	vec = Vector3D( M[0][0] * v.x + M[0][1] * v.y + M[0][2] * v.z,
	                  M[1][0] * v.x + M[1][1] * v.y + M[1][2] * v.z,
	                  M[2][0] * v.x + M[2][1] * v.y + M[2][2] * v.z);
	return vec;
}


#endif
