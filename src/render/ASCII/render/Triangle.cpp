
#include "render/ASCII/render/Triangle.h"
#include <algorithm>

namespace asc 
{

void Triangle::draw()
{
    const int X1 = (a.x * 16)+ 0.5;
    const int X2 = (b.x * 16)+ 0.5;
    const int X3 = (c.x * 16)+ 0.5;

    const int Y1 = (a.y * 16)+ 0.5;
    const int Y2 = (b.y * 16)+ 0.5;
    const int Y3 = (c.y * 16)+ 0.5;

    const int DX12 = a.x - b.x;
    const int DX23 = b.x - c.x;
    const int DX31 = c.x - a.x;
    
    const int DY12 = a.y - b.y;
    const int DY23 = b.y - c.y;
    const int DY31 = c.y - a.y;

    const int FDX12 = DX12 << 4;
    const int FDX23 = DX23 << 4;
    const int FDX31 = DX31 << 4;

    const int FDY12 = DY12 << 4;
    const int FDY23 = DY23 << 4;
    const int FDY31 = DY31 << 4;

    int minx = (std::min({ X1, X2, X3 }) + 0xF) >> 4;
    int maxx = (std::max({ X1, X2, X3 }) + 0xF) >> 4;
    int miny = (std::min({ Y1, Y2, Y3 }) + 0xF) >> 4;
    int maxy = (std::max({ Y1, Y2, Y3 }) + 0xF) >> 4;

}

}
