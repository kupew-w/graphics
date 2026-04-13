#pragma once

#include "geomtery/Line2D.h"
#include "geomtery/Triagle2D.h"
#include "objects/Color.h"

namespace gp 
{

class IWindow
{
protected:
    int width, height;

public:
    IWindow(int w, int h) : width(w), height(h) {}

    virtual void drawPixel(int x, int y, Color color) = 0;
    virtual void drawLine(Line2D) = 0;
    virtual void drawTriangle(Triangle2D) = 0;

    virtual void clear() = 0;
    virtual void display() = 0;

    int getWigth() { return width; }
    int getHeight() { return height; }

    IWindow() = default;
    IWindow(IWindow&&) = default;
    IWindow& operator=(IWindow&&) = default;

    IWindow(const IWindow&) = delete;
    IWindow& operator=(const IWindow&) = delete;

    virtual ~IWindow() = default;
};

}
