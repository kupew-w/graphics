
#include "objects/Camera.h"
#include "math/Mat4.h"
#include <cmath>
#include <numbers>

using namespace gp;

Camera::Camera()
{}

void Camera::rotate(float yaw, float pitch, float roll)
{
//FIXME
}

Mat4 Camera::viewMatrix()
{
    Mat4 out;

    Vec3 f = dir.normalize();
    Vec3 r = Vec3::crossProd(up,f).normalize();
    Vec3 u = Vec3::crossProd(r, f);

    out.mat[0][0] = r.x;
    out.mat[1][0] = r.y;
    out.mat[2][0] = r.z;

    out.mat[0][1] = u.x;
    out.mat[1][1] = u.y;
    out.mat[2][1] = u.z;

    out.mat[0][2] = -f.x;
    out.mat[1][2] = -f.y;
    out.mat[2][2] = -f.z;

    out.mat[3][0] = -Vec3::dotProd(u, possition);
    out.mat[3][1] = -Vec3::dotProd(f, possition);
    out.mat[3][2] = Vec3::dotProd(r, possition);
    out.mat[3][3] = 1;

    return out;
}

Mat4 Camera::projectionMatrix()
{
    Mat4 out;

    float s = 1/std::tan(fov/2*std::numbers::pi/180);
    out.mat[0][0] = s/aspect;
    out.mat[1][1] = s;
    out.mat[2][2] = (f+n)/(n-f);
    out.mat[3][2] = (2*f*n)/(n-f);
    out.mat[2][3] = -1.0f;
    out.mat[3][3] = 0;

    return out;
}
