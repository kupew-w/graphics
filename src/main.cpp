#include "geomtery/Triagle2D.h"
#include "geomtery/Vertex2D.h"
#include "render/ASCII/window/Window.h"

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
    gp::Vertex2D v = {{0,0}, {255,255,255}};
    triangle.a = v;
    v = {{0,20}, {255,255,255}};
    triangle.b = v;
    v = {{20,0}, {255,255,255}};
    triangle.c = v;
    gp::Triangle2D triangle2 = {
        {{30,height}, {255,0,255}}, 
        {{50,height}, {0,255,255}}, 
        {{50,30}, {255,255,0}}};

    window.init();
    window.clear();
    window.drawTest();
    window.drawTriangle(triangle);
    window.drawTriangle(triangle2);
    window.display();
    //std::cout << width << " :w\t" << height << " :h\n";
    sleep(5);
    window.close();

	return 0;
}
