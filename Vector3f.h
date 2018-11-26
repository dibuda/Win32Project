#pragma once
#include <math.h>
class Vector3f
{
public:
	Vector3f(float x=0.0f,float y=0.0f,float z=0.0);
	Vector3f operator+(Vector3f &r);
	Vector3f operator-(Vector3f &r);
	Vector3f operator*(float scaler);
	float operator*(Vector3f &r);
	void operator=(const Vector3f&r);
	void Normalize();
	float Magnitudel();

	//~Vector3f();
	float x, y, z;


private:

};
Vector3f Cross(Vector3f v1, Vector3f v2);