#include "objects/Color.h"

using namespace gp;


Color Color::operator+ (const Color& v) const
{ return Color(r + v.r, g + v.g, b + v.b, 1); }

Color Color::operator- (const Color& v) const
{ return Color(r - v.r, g - v.g, b - v.b, 1); }

Color Color::operator* (const float a) const
{ return Color(r * a, g * a, b * a, 1); }

Color Color::operator/ (const float a) const
{ return Color(r / a, g / a, b / a, 1); }

void Color::operator+= (const Color& v)
{ r += v.r; g += v.g; b += v.b; }

void Color::operator-= (const Color& v)
{ r -= v.r; g -= v.g; b -= v.b; }

void Color::operator*= (const float a)
{ r *= a; g *= a; b *= a; }

void Color::operator/= (const float a)
{ r /= a; g /= a; b /= a; }
