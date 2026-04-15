#pragma once

#include "render/IWindow.h"
#include "render/ASCII/render/Pixel.h"
#include <vector>

namespace gp {
namespace asc 
{

class Window : public IWindow
{
private:
    std::vector<std::vector<Pixel>> buffer;

public:
    Window(int w, int h); 

    void init() override;
    void close() override;
 
    void drawPixel(int x, int y, gp::Color c) override;
    void drawLine(gp::Line2D) override;
    void drawTriangle(gp::Triangle2D) override;
    void drawTest();

    void clear() override;
    void display() override;
};

}}
