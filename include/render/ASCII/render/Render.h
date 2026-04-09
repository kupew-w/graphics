#pragma once

#include "render/IRender.h"
#include <string>

namespace asc 
{

class Render : public gp::IRender
{
public:
    void drawPixel(int x, int y, gp::Color c) override;
    void drawLine(gp::Line2D) override;
    void drawTriangle(gp::Triangle2D) override;

    void clear() override;
    std::string getBuffer() override;
};

}
