#include "math/Vec3.h"
#include "math/Vec4.h"

namespace gp 
{

Vec3::Vec3(Vec4 v): x(v.x), y(v.y), z(v.z) {}

Vec4::Vec4(Vec3 v): x(v.x), y(v.y), z(v.z), w(1) {}

}
