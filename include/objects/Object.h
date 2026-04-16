#pragma once 
#include "math/Vec3.h"
#include "objects/Mesh.h"

#include <memory>

namespace gp
{

class Object
{
    gp::Vec3 coordinates, scale;

    std::shared_ptr<gp::Mesh> mesh;

    float mass;

    //TODO add hitbox

    Object(Vec3 coordinates) : coordinates(coordinates), scale({1, 1, 1}), mass(0) {}
    Object(std::shared_ptr<Mesh> mesh) : mesh(mesh) { Object(Vec3({0, 0, 0})); }
    Object(Vec3 coordinates, std::shared_ptr<Mesh> mesh) : mesh(mesh) { Object(Vec3(coordinates)); }
};

}
