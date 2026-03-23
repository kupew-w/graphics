#pragma once

#include "Math/Vec3.h"
#include "objects/Mesh.h"

#include <memory>

namespace gp
{

struct Object
{
    gp::Vec3 coordinates, position, scale;

    std::unique_ptr<gp::Mesh> mesh;

    float mass;
};

}
