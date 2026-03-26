#pragma once

#include "math/Vec2.h"
#include "render/ASCII/render/Drawble.h"

namespace asc 
{

class Triangle : Drawble
{
public:
    gp::Vec2 a, b, c;
    
    Triangle(gp::Vec2 a, gp::Vec2 b, gp::Vec2 c) : a(a), b(b), c(c) {}

    Triangle(Triangle&&) = default;
    Triangle &operator=(Triangle &&) = default;
    ~Triangle() = default;

    Triangle(const Triangle&) = delete;
    Triangle &operator=(const Triangle&) = delete;

    void draw() override;    
};

}
