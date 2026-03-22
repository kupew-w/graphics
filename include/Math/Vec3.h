#pragma once

namespace gp 
{

struct Vec3
{
    float x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3(Vec3&&) = default;
    Vec3(const Vec3&) = default;
    Vec3 &operator=(Vec3 &&) = default;
    Vec3 &operator=(const Vec3&) = default;
    ~Vec3() = default;

    Vec3 operator+ (const Vec3&) const;
    Vec3 operator- (const Vec3&) const;
    Vec3 operator* (const float) const;
    Vec3 operator/ (const float) const;

    void operator+= (const Vec3&);
    void operator-= (const Vec3&);
    void operator*= (const float);
    void operator/= (const float);

    Vec3 normalize() ;
    float lenght();

    static Vec3 crossProd(const Vec3&, const Vec3&);
    static float dotProd(const Vec3&, const Vec3&);
};

}
