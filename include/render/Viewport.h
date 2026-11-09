#pragma once 

namespace gp 
{

struct Viewport
{
    int x, y;
    int width, height;

    Viewport(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
};

}
