#pragma once

#include "geomtery/Triangle.h"
#include "objects/Camera.h"
#include "objects/Object.h"
#include <vector>

namespace gp 
{

class Projection
{
public:
    static std::vector<Triangle> projectObject(const Object&, const Camera&);
};

}
