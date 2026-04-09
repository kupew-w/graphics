#pragma once

#include "geomtery/Line2D.h"
#include "geomtery/Triagle2D.h"
#include "objects/Color.h"
#include <string>

namespace gp 
{

class IRender
{
protected:
    std::string buffer;

    int width, height;

public:
    virtual void drawPixel(int x, int y, Color color) = 0;
    virtual void drawLine(Line2D) = 0;
    virtual void drawTriangle(Triangle2D) = 0;

    virtual void clear() = 0;
    virtual std::string getBuffer() = 0;

    IRender() = default;
    IRender(IRender&&) = default;
    IRender& operator=(IRender&&) = default;

    IRender(const IRender&) = delete;
    IRender& operator=(const IRender&) = delete;

    virtual ~IRender() = default;
};

}
