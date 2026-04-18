#include "math/Mat4.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include <cmath>

using namespace gp;

Mat4::Mat4()
{
    for(int i = 0; i < 4; ++i)
        for(int j = 0; i < 4; ++j)
            mat[i][j] = 0;
}

Mat4 Mat4::operator*(const float a)
{
    Mat4 out;

    for(int i = 0; i < 4; ++i)
        for(int j = 0; i < 4; ++j)
            out.mat[i][j] = mat[i][j] * a;

    return out;
}

Vec4 Mat4::operator*(const Vec4& v)
{
    Vec4 out;

    out.x += v.x*mat[0][0] + v.y*mat[0][1] + v.z*mat[0][2] + v.w*mat[0][3];
    out.y += v.x*mat[1][0] + v.y*mat[1][1] + v.z*mat[1][2] + v.w*mat[1][3];
    out.z += v.x*mat[2][0] + v.y*mat[2][1] + v.z*mat[2][2] + v.w*mat[2][3];
    out.w += v.x*mat[3][0] + v.y*mat[3][1] + v.z*mat[3][2] + v.w*mat[3][3];

    return out;
}

Vec3 Mat4::operator*(const Vec3& v)
{
    Vec4 t;

    t = operator*(Vec4(v.x, v.y, v.z, 1));

    return {t.x, t.y, t.z};
}

Mat4 Mat4::operator*(const Mat4& m)
{
    Mat4 out;

    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            out.mat[i][j] = mat[i][0]*m.mat[0][i] + mat[i][1]*m.mat[1][i] + mat[i][2]*m.mat[2][i] + mat[i][3]*m.mat[3][i];

    return out;
}

void Mat4::operator*=(const float a)
{
     for(int i = 0; i < 4; ++i)
        for(int j = 0; i < 4; ++j)
            mat[i][j] *= a;
}
        
void Mat4::operator*=(const Mat4& mat)
{
//FIXME
}

Mat4 Mat4::rotationMatrix(float yaw, float pitch, float roll)
{
    Mat4 out;

    out.mat[0][0] = cos(yaw)*cos(pitch);
    out.mat[1][0] = cos(yaw)*sin(pitch)*sin(roll)-sin(yaw)*cos(roll);
    out.mat[2][0] = cos(yaw)*sin(pitch)*cos(roll)+sin(yaw)*sin(roll);
    out.mat[0][1] = sin(yaw)*cos(pitch);
    out.mat[1][1] = sin(yaw)*sin(pitch)*sin(roll)+cos(yaw)*cos(roll);
    out.mat[2][1] = sin(yaw)*sin(pitch)*cos(roll)-cos(yaw)*sin(roll);
    out.mat[0][2] = -sin(pitch);
    out.mat[1][2] = cos(pitch)*sin(roll);
    out.mat[2][2] = cos(pitch)*cos(roll);
    out.mat[3][3] = 1;

    return out;
}
