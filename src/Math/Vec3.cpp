#include "Math/Vec3.h"
#include <cmath>

using namespace gp;


Vec3 Vec3::operator+ (const Vec3& v) const
{ return Vec3(x + v.x, y + v.y, z + v.z); }

Vec3 Vec3::operator- (const Vec3& v) const
{ return Vec3(x - v.x, y - v.y, z - v.z); }

Vec3 Vec3::operator* (const float a) const
{ return Vec3(x * a, y * a, z * a); }

Vec3 Vec3::operator/ (const float a) const
{ return Vec3(x / a, y / a, z / a); }

void Vec3::operator+= (const Vec3& v)
{ x += v.x; y += v.y; z += v.z; }

void Vec3::operator-= (const Vec3& v)
{ x -= v.x; y -= v.y; z -= v.z; }

void Vec3::operator*= (const float a)
{ x *= a; y *= a; z *= a; }

void Vec3::operator/= (const float a)
{ x /= a; y /= a; z /= a; }

Vec3 Vec3::normalize() 
{ return *this / this->lenght(); }

float Vec3::lenght()
{ return sqrt(x*x + y*y + z*z); }

Vec3 Vec3::crossProd(const Vec3& v1, const Vec3& v2)
{ 
    return Vec3 ((v1.y * v2.z - v1.z * v2.y), 
                (v1.x * v2.z - v1.z * v2.x), 
                (v1.x * v2.y - v1.y * v2.x)); 
}

float Vec3::dotProd(const Vec3& v1, const Vec3& v2)
{ return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z; }

