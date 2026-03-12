#pragma once

#include <vector>

#include "Math/Vector.h"

namespace gp 
{

class Polygon
{
private:
    std::vector<gp::Vector> points;

public:
    Polygon() = delete;

    Polygon(std::vector<gp::Vector>&& points) : points(std::move(points)) {}
};

}
