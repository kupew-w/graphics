#pragma once

#include "math/Vec3.h"
#include "math/Vec4.h"
namespace gp 
{

struct Mat4
{
    float mat[4][4];

    Mat4(); //set all elemets 0

    Mat4 operator* (const float);
    Vec4 operator* (const Vec4&);
    Vec3 operator* (const Vec3&);
    Mat4 operator* (const Mat4&);

    void operator*= (const float);
    void operator*= (const Mat4&);

    static Mat4 rotationMatrix(float yaw, float pitch, float roll);
};

}
