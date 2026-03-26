#include "math/Vec2.h"
#include <cmath>

using namespace gp;


Vec2 Vec2::operator+ (const Vec2& v) const
{ return Vec2(x + v.x, y + v.y); }

Vec2 Vec2::operator- (const Vec2& v) const
{ return Vec2(x - v.x, y - v.y); }

Vec2 Vec2::operator* (const float a) const
{ return Vec2(x * a, y * a); }

Vec2 Vec2::operator/ (const float a) const
{ return Vec2(x / a, y / a); }

void Vec2::operator+= (const Vec2& v)
{ x += v.x; y += v.y; }

void Vec2::operator-= (const Vec2& v)
{ x -= v.x; y -= v.y; }

void Vec2::operator*= (const float a)
{ x *= a; y *= a; }

void Vec2::operator/= (const float a)
{ x /= a; y /= a; }

Vec2 Vec2::normalize() 
{ return *this / this->lenght(); }

float Vec2::lenght()
{ return sqrt(x*x + y*y); }

float Vec2::crossProd(const Vec2& v1, const Vec2& v2)
{ 
    return v1.x * v2.y - v1.y * v2.x; 
}

float Vec2::dotProd(const Vec2& v1, const Vec2& v2)
{ return v1.x*v2.x + v1.y*v2.y; }

