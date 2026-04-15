#pragma once 

namespace gp {
namespace asc 
{

struct Pixel
{
    char c;
    float z;

    Pixel(char c, float z) : c(c), z(z) {}
};

}}
