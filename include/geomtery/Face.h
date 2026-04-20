#pragma once

namespace gp 
{

struct Face
{
    int a = 0, b = 0, c = 0;

    Face() = default;
    Face(int a, int b, int c) : a(a), b(b), c(c) {}
};

}
