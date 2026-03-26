#pragma once

namespace gp 
{

struct Vec4
{
    float x, y, z, w;

    Vec4() : x(0), y(0), z(0), w(1) {}
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    ~Vec4() = default;

    Vec4 operator+ (const Vec4&) const;
    Vec4 operator- (const Vec4&) const;
    Vec4 operator* (const float) const;
    Vec4 operator/ (const float) const;

    void operator+= (const Vec4&);
    void operator-= (const Vec4&);
    void operator*= (const float);
    void operator/= (const float);
};

}
