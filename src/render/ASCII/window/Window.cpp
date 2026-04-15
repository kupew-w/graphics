
#include "render/ASCII/window/Window.h"
#include "render/ASCII/render/Color.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <ostream>

using namespace gp;
using namespace asc;

Window::Window(int w, int h) : IWindow(w, h) 
{
    buffer = std::vector(h, std::vector<Pixel>(w, Pixel(' ', INT_MAX)));
}

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

void Window::clear()
{
    std::cout << "\x1b[2J"; //clear screen
    std::cout << "\x1b[H"; //move cursor to 0 0 
}

void Window::display()
{
    std::cout << "\x1b[H"; //move cursor to 0 0 
    
    std::string screen;
    screen.reserve(height*width+height);

    //std::cout << height << " :h\t" << width << " :w\n";
    for(int y = 0; y < height; ++y) {
        for(int x = 0; x < width; ++x) 
        {
            screen += buffer[y][x].c;
        }
        screen += '\n';
    }
    
    std::cout << screen << std::flush;
}

void Window::drawPixel(int x, int y, gp::Color c)
{
    if(x < 0 || x >= width || y < 0 || y >= height) return;
    buffer[y][x].c = AsciiColor::cts(c); // add z-buffer check
}

void Window::drawTest()
{
    buffer[0][0].c = '#';
}

void Window::drawLine(gp::Line2D l)
{
    int x1 = l.a.position.x;
    int x2 = l.b.position.x;
    int y1 = l.a.position.y;
    int y2 = l.b.position.y;

    const int dX = std::abs(x2 - x1);
    const int dY = std::abs(y2 - y1);

    const int sX = x1 < x2 ? 1 : -1;
    const int sY = y1 < y2 ? 1 : -1;

    int error = dX-dY;

    while(x1 != x2 || y1 != y2)
    {
        drawPixel(x1, y1, {}); //FIXME chage to buffer
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

void Window::drawTriangle(gp::Triangle2D t)
{
    const int X1 = (t.a.position.x * 16)+ 0.5;
    const int X2 = (t.b.position.x * 16)+ 0.5;
    const int X3 = (t.c.position.x * 16)+ 0.5;

    const int Y1 = (t.a.position.y * 16)+ 0.5;
    const int Y2 = (t.b.position.y * 16)+ 0.5;
    const int Y3 = (t.c.position.y * 16)+ 0.5;

    const int DX12 = t.a.position.x - t.b.position.x;
    const int DX23 = t.b.position.x - t.c.position.x;
    const int DX31 = t.c.position.x - t.a.position.x;
    
    const int DY12 = t.a.position.y - t.b.position.y;
    const int DY23 = t.b.position.y - t.c.position.y;
    const int DY31 = t.c.position.y - t.a.position.y;

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

    float C1 = DY12 * X1 - DX12 * Y1;
    float C2 = DY23 * X2 - DX23 * Y2;
    float C3 = DY31 * X3 - DX31 * Y3;

    if(DY12 < 0 || (DY12 == 0 && DX12 > 0)) ++C1;
    if(DY23 < 0 || (DY23 == 0 && DX23 > 0)) ++C2;
    if(DY31 < 0 || (DY31 == 0 && DX31 > 0)) ++C3;

    int CY1 = C1 + DX12 * (miny << 4) - DY12 * (minx << 4);
    int CY2 = C2 + DX23 * (miny << 4) - DY23 * (minx << 4);
    int CY3 = C3 + DX31 * (miny << 4) - DY31 * (minx << 4);

    float Sabc = (DX31*DY12)-(DX12*DY31);
    if(std::abs(Sabc) < 1e-5f) return;

    for(int y = miny; y < maxy; ++y)
    {
        int CX1 = CY1;
        int CX2 = CY2;
        int CX3 = CY3;

        for(int x = minx; x < maxx; ++x)
        {
            if(CX1 > 0 && CX2 > 0 && CX3 > 0)
            {
                //Color
                float u = Vec2::crossProd({-DX23, -DY23}, {x-X2, y-Y2})/Sabc;
                float w = Vec2::crossProd({DX12, DY12}, {x-X2, y-Y2})/Sabc;
                float v = 1-u-w;

                Color c = t.a.color*u+t.b.color*v+t.c.color*w;
                c.r = std::clamp<float>(c.r, 0.0f, 255.0f);
                c.g = std::clamp<float>(c.g, 0.0f, 255.0f);
                c.b = std::clamp<float>(c.b, 0.0f, 255.0f);
                drawPixel(x, y, c); 
            }

            CX1 -= FDY12;
            CX2 -= FDY23;
            CX3 -= FDY31;
        }

        CY1 += FDX12;
        CY2 += FDX23;
        CY3 += FDX31;
    }
}
