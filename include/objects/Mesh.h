#pragma once

#include "geomtery/Vertex.h"
#include "geomtery/Face.h"
#include <vector>

namespace  gp 
{

struct Mesh
{
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
};

}

