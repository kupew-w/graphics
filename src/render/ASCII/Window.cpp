
#include "render/ASCII/Window.h"
#include "math/Vec3.h"
#include "math/Vec2.h"
#include <iostream>

using namespace gp;
using namespace asc;

void Window::init()
{
    std::cout << "\x1b[?1049h"; //enable alternate buffer
    std::cout << "\x1b[?25l"; //hide cursor
    std::cout << "\x1b[H"; // move cursor to 0 0
}

void Window::close()
{
    std::cout << "\x1b[?25h"; //show cursor
    std::cout << "\x1b[?1049l"; //disable alternate buffer
}

Vec2 Window::toScreen(Vec3 v)
{
    Vec2 out;

    out.x = (v.x + 1) * 0.5f * w; 
    out.y = (1 - v.y) * 0.5f * h; 

    return out;
}
