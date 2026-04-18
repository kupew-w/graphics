#include "fstream/FObj.h"
#include "geomtery/Face.h"
#include "geomtery/Triagle2D.h"
#include "geomtery/Triangle.h"
#include "geomtery/Vertex2D.h"
#include "objects/Camera.h"
#include "render/ASCII/window/Window.h"

#include <iostream>
#include <memory>
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
    gp::FObj reader;

    std::shared_ptr<gp::Mesh> enderRodMesh = std::make_shared<gp::Mesh>();

    try 
    {
        enderRodMesh = reader.read("source/ender stick.obj");
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what();
    }

    gp::Object enderRod(enderRodMesh);

    gp::Camera cam;

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

    for(gp::Face f : enderRodMesh->faces)
    {
        gp::Triangle t;
        t.a = enderRodMesh->vertices[f.a];
        t.b = enderRodMesh->vertices[f.b];
        t.c = enderRodMesh->vertices[f.c];

        std::cout << "1test\n";

        t.a.position = cam.projectionMatrix() * cam.viewMatrix() * enderRod.modelMatrix() * t.a.position;
        t.b.position = cam.projectionMatrix() * cam.viewMatrix() * enderRod.modelMatrix() * t.b.position;
        t.c.position = cam.projectionMatrix() * cam.viewMatrix() * enderRod.modelMatrix() * t.c.position;
    }

    //std::cout << width << " :w\t" << height << " :h\n";
    sleep(5);
    window.close();

	return 0;
}
