#pragma once

#include "math/Vec2.h"
#include "objects/Color.h"

namespace gp 
{

struct Vertex2D
{
    Vec2 position;
    Color color;
    float z;
};

}
