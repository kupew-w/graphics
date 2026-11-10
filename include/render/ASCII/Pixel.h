#pragma once 

namespace gp {
namespace asc 
{

struct Pixel
{
    char c = ' ';
    float z = 1;

    Pixel() = default;
    Pixel(char c, float z) : c(c), z(z) {}
};

}}
