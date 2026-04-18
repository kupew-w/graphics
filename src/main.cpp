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

    window.init();
    window.clear();
    window.drawTest();
    window.display();
    //std::cout << width << " :w\t" << height << " :h\n";
    sleep(5);
    window.close();

	return 0;
}
