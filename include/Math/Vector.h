#pragma once

namespace gp 
{

class Vector
{
private: 
    float x, y, z, w;

public:
    Vector() : x(0), y(0), z(0), w(1) {}
    Vector(float x, float y, float z) : x(x), y(y), z(z), w(1) {}

    Vector(Vector&&) = default;
    Vector(const Vector&) = default;
    Vector &operator=(Vector &&) = default;
    Vector &operator=(const Vector&) = default;
    ~Vector() = default;

    Vector operator+ (const Vector&);
    Vector operator- (const Vector&);
    Vector operator* (const float);
    Vector operator/ (const float);

    void operator+= (const Vector&);
    void operator-= (const Vector&);
    void operator*= (const float);
    void operator/= (const float);

    Vector normalize();
    float lenght();

    static Vector crossProd(Vector, Vector);
    static float dotProd(Vector, Vector);
};

}
