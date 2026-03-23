#pragma once

#include "objects/Object.h"

namespace gp 
{

class Window
{
private:


public:
    Window();

    void init();
    void shutdown();

    void clear();
    void draw(Object&);
    void display();
};

}
