#pragma once 

#include "math/Mat4.h"
#include "math/Vec3.h"
#include "objects/Mesh.h"

#include <memory>

namespace gp
{

struct Object
{
    Vec3 position, scale;

    float yaw = 0, pitch = 0, roll = 0;

    std::shared_ptr<Mesh> mesh;

    float mass;

    //TODO add hitbox

    Object(Vec3 coordinates) : position(coordinates), scale({1, 1, 1}), mass(0) {}
    Object(std::shared_ptr<Mesh> mesh) : mesh(mesh) { Object(Vec3({0, 0, 0})); }
    Object(Vec3 coordinates, std::shared_ptr<Mesh> mesh) : mesh(mesh) { Object(Vec3(coordinates)); }

    Mat4 modelMatrix();
};

}
