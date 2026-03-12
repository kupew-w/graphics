#pragma once

#include "Math/Vector.h"

namespace gp
{

class Object
{
private:
    gp::Vector coordinates;

public:
    Object(gp::Vector coordinates) : coordinates(coordinates) {}
    Object(float x, float y, float z) : coordinates(x, y, z) {}
};

}
