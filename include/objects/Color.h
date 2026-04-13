#pragma once

namespace gp 
{

struct Color
{
    float r, g, b, a;

    Color() : r(0), g(0), b(0), a(1) {} 
    Color(float r, float g, float b, float a = 1) : r(r), g(g), b(b), a(a) {}

    ~Color() = default;

    Color operator+ (const Color&) const;
    Color operator- (const Color&) const;
    Color operator* (const float) const;
    Color operator/ (const float) const;

    void operator+= (const Color&);
    void operator-= (const Color&);
    void operator*= (const float);
    void operator/= (const float);
};

}
