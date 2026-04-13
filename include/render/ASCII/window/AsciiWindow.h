#pragma once

#include "render/IWindow.h"
#include <vector>

namespace gp 
{

class AsciiWindow : public IWindow
{
private:
    std::vector<std::vector<char>> buffer;

public:
    AsciiWindow(int w, int h); 

    void drawPixel(int x, int y, gp::Color c) override;
    void drawLine(gp::Line2D) override;
    void drawTriangle(gp::Triangle2D) override;

    void clear() override;
};

}
