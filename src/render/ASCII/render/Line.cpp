

#include "render/ASCII/render/Line.h"
#include <cstdlib>

namespace asc 
{

void Line::draw()
{
    //Bresenhame
    int x1 = a.x;
    int x2 = b.x;
    int y1 = a.y;
    int y2 = b.y;

    const int dX = std::abs(x2 - x1);
    const int dY = std::abs(y2 - y1);

    const int sX = x1 < x2 ? 1 : -1;
    const int sY = y1 < y2 ? 1 : -1;

    int error = dX-dY;

    while(x1 != x2 || y1 != y2)
    {
        //setPixer
        int error2 = error * 2;
        
        if(error2 > -dY)
        {
            error -= dY;
            x1 += sX;
        }
        if(error2 > dX)
        {
            error += dX;
            y1 += sY;
        }
    }
}

}
