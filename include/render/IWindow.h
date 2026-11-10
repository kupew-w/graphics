#pragma once

namespace gp 
{

class IWindow
{
protected:
    int w = 0, h = 0;

public:
    IWindow(int w, int h) : w(w), h(h) {}

    virtual void init() = 0;
    virtual void close() = 0;

    // virtual void drawPixel(int x, int y, Color color) = 0;
    // virtual void drawLine(Line2D) = 0;
    // virtual void drawTriangle(Triangle2D) = 0;

    int width() const { return w; }
    int height() const { return h; }

    IWindow() = default;
    IWindow(IWindow&&) = default;
    IWindow& operator=(IWindow&&) = default;

    IWindow(const IWindow&) = delete;
    IWindow& operator=(const IWindow&) = delete;

    virtual ~IWindow() = default;
};

}
