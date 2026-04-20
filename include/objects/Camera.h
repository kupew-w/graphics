#pragma once

#include "math/Mat4.h"
#include "math/Vec3.h"

namespace gp 
{

struct Camera
{
    Vec3 possition = {0, 0, 0};
    Vec3 dir = {0, 0, 1};
    Vec3 up = {0, 1, 0};
    float fov = 90, n = 0.1, f = 1000, aspect = 16.0f/9.0f;


    Camera();
    Camera(float fov, float n, float f) : 
    fov(fov), n(n), f(f) {}

    void rotate(float yaw, float pitch, float roll);

    Mat4 viewMatrix();
    Mat4 projectionMatrix();
};

}
