
#include "objects/Camera.h"
#include "math/Mat4.h"
#include <cmath>
#include <numbers>

using namespace gp;

void Camera::rotate(float yaw, float pitch, float roll)
{
//FIXME
}

Mat4 Camera::viewMatrix()
{
    Mat4 out;

    Vec3 N = Vec3::crossProd(dir, up);

    out.mat[0][0] = up.x;
    out.mat[1][0] = up.y;
    out.mat[2][0] = up.z;

    out.mat[0][1] = dir.x;
    out.mat[1][1] = dir.y;
    out.mat[2][1] = dir.z;

    out.mat[0][2] = N.x;
    out.mat[1][2] = N.y;
    out.mat[2][2] = N.z;

    out.mat[4][0] = -Vec3::dotProd(up, possition);
    out.mat[4][1] = -Vec3::dotProd(dir, possition);
    out.mat[4][2] = -Vec3::dotProd(N, possition);
    out.mat[4][3] = 1;

    return out;
}

Mat4 Camera::projectionMatrix()
{
    Mat4 out;

    float s = 1/std::tan(fov/2*std::numbers::pi/180);
    out.mat[0][0] = s;
    out.mat[1][1] = s;
    out.mat[2][2] = -f/(f-n);
    out.mat[3][2] = -f*n/(f-n);
    out.mat[2][3] = -1;

    return out;
}
