#pragma once

namespace gp 
{

struct Vec2
{
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(int x, int y) : x(x), y(y) {}
    Vec2(float x, float y) : x(x), y(y) {}

    ~Vec2() = default;

    Vec2 operator+ (const Vec2&) const;
    Vec2 operator- (const Vec2&) const;
    Vec2 operator* (const float) const;
    Vec2 operator/ (const float) const;

    void operator+= (const Vec2&);
    void operator-= (const Vec2&);
    void operator*= (const float);
    void operator/= (const float);

    Vec2 normalize();
    float lenght();

    static float crossProd(const Vec2&, const Vec2&);
    static float dotProd(const Vec2&, const Vec2&);
};

}
