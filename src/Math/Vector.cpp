#include "Math/Vector.h"
#include <cmath>

using namespace gp;

Vector Vector::operator+ (const Vector& v)
{ return Vector(x + v.x, y + v.y, z + v.z); }

Vector Vector::operator- (const Vector& v)
{ return Vector(x - v.x, y - v.y, z - v.z); }

Vector Vector::operator* (const float a)
{ return Vector(x * a, y * a, z * a); }

Vector Vector::operator/ (const float a)
{ return Vector(x / a, y / a, z / a); }

void Vector::operator+= (const Vector& v)
{ x += v.x; y += v.y; z += v.z; }

void Vector::operator-= (const Vector& v)
{ x -= v.x; y -= v.y; z -= v.z; }

void Vector::operator*= (const float a)
{ x *= a; y *= a; z *= a; }

void Vector::operator/= (const float a)
{ x /= a; y /= a; z /= a; }

Vector Vector::normalize()
{ return (*this / this->lenght()); }

float Vector::lenght()
{ return sqrt(x*x + y*y + z*z); }

Vector Vector::crossProd(Vector v1, Vector v2)
{ 
    return Vector((v1.y * v2.z - v1.z * v2.y), 
                (v1.x * v2.z - v1.z * v2.x), 
                (v1.x * v2.y - v1.y * v2.x)); 
}

float Vector::dotProd(Vector v1, Vector v2)
{ return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z; }

