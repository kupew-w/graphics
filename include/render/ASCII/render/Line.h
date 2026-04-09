#pragma once

#include "math/Vec2.h"

namespace asc 
{

struct Line 
{
    gp::Vec2 a, b;

    Line(gp::Vec2 a, gp::Vec2 b) : a(a), b(b) {}

    Line(Line&&) = default;
    Line &operator=(Line &&) = default;
    ~Line() = default;

    Line(const Line&) = delete;
    Line &operator=(const Line&) = delete;
};

}
