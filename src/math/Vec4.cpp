#include "math/Vec4.h"

using namespace gp;


Vec4 Vec4::operator+ (const Vec4& v) const
{ return Vec4(x + v.x, y + v.y, z + v.z, 1); }

Vec4 Vec4::operator- (const Vec4& v) const
{ return Vec4(x - v.x, y - v.y, z - v.z, 1); }

Vec4 Vec4::operator* (const float a) const
{ return Vec4(x * a, y * a, z * a, 1); }

Vec4 Vec4::operator/ (const float a) const
{ return Vec4(x / a, y / a, z / a, 1); }

void Vec4::operator+= (const Vec4& v)
{ x += v.x; y += v.y; z += v.z; }

void Vec4::operator-= (const Vec4& v)
{ x -= v.x; y -= v.y; z -= v.z; }

void Vec4::operator*= (const float a)
{ x *= a; y *= a; z *= a; }

void Vec4::operator/= (const float a)
{ x /= a; y /= a; z /= a; }
