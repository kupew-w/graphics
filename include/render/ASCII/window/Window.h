#pragma once

#include "render/ASCII/render/Drawble.h"

namespace asc 
{

class Window
{
private:


public:
    Window();

    void init();
    void shutdown();

    void clear();
    void draw(Drawble&);
    void display();
};

}
