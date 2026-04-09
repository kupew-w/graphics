#pragma once

#include <string>
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
    void display(std::string buffer);
};

}
