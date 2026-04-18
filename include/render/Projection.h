#pragma once

#include "geomtery/Triagle2D.h"
#include "objects/Camera.h"
#include "objects/Object.h"
#include <vector>

namespace gp 
{

class Projection
{
public:
    std::vector<Triangle2D> projectObject(const Object&, const Camera&);
};

}
