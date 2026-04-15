#include "geomtery/Triagle2D.h"
#include "geomtery/Vertex2D.h"
#include "render/ASCII/window/Window.h"

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
    struct winsize w;
    int width;
    int height;
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
    {
        width = w.ws_col;
        height = w.ws_row;
    }

    gp::asc::Window window(width, height);

    gp::Triangle2D triangle;
    gp::Vertex2D v = {{0,0}, {255,255,0}};
    triangle.a = v;
    v = {{0,height}, {255,0,255}};
    triangle.b = v;
    v = {{width,0}, {0,255,255}};
    triangle.c = v;

    window.init();
    window.clear();
    window.drawTest();
    //std::cout << width << " :w\t" << height << " :h\n";
    window.drawTriangle(triangle);
    window.display();
    sleep(5);
    window.close();

	return 0;
}
