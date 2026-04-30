#include "objects/Object.h"
#include "math/Mat4.h"

#include <cmath>

using namespace gp;

Mat4 Object::modelMatrix() const
{
    Mat4 out;

    out.mat[0][0] = scale.x*cos(yaw)*cos(pitch);
    out.mat[1][0] = scale.y*cos(yaw)*sin(pitch)*sin(roll)-sin(yaw)*cos(roll);
    out.mat[2][0] = scale.z*cos(yaw)*sin(pitch)*cos(roll)+sin(yaw)*sin(roll);
    out.mat[0][1] = scale.x*sin(yaw)*cos(pitch);
    out.mat[1][1] = scale.y*sin(yaw)*sin(pitch)*sin(roll)+cos(yaw)*cos(roll);
    out.mat[2][1] = scale.z*sin(yaw)*sin(pitch)*cos(roll)-cos(yaw)*sin(roll);
    out.mat[0][2] = scale.x*-sin(pitch);
    out.mat[1][2] = scale.y*cos(pitch)*sin(roll);
    out.mat[2][2] = scale.z*cos(pitch)*cos(roll);
    out.mat[3][0] = position.x;
    out.mat[3][1] = position.y;
    out.mat[3][2] = position.z;
    out.mat[3][3] = 1;

    return out;
}
