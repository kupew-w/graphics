#include "fstream/FObj.h"
#include "geomtery/Face.h"
#include "geomtery/Triangle2D.h"
#include "geomtery/Triangle.h"
#include "geomtery/Vertex.h"
#include "geomtery/Vertex2D.h"
#include "math/Mat4.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include "objects/Camera.h"
#include "objects/Object.h"
#include "render/ASCII/window/Window.h"
#include "render/Projection.h"

#include <iostream>
#include <memory>
#include <numbers>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

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

    std::shared_ptr<gp::Mesh> mcube = std::make_shared<gp::Mesh>();
    
    mcube->vertices.push_back(gp::Vertex({2, 2, 2}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({2, 2, -2}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({2, -2, 2}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({2, -2, -2}, {255,255,255}));

    mcube->vertices.push_back(gp::Vertex({-2, 2, 2}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({-2, 2, -2}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({-2, -2, 2}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({-2, -2, -2}, {255,255,255}));


    mcube->faces.push_back(gp::Face(0, 2, 1));
    mcube->faces.push_back(gp::Face(1, 2, 3));

    mcube->faces.push_back(gp::Face(0, 1, 4));
    mcube->faces.push_back(gp::Face(1, 5, 4));

    mcube->faces.push_back(gp::Face(4, 5, 6));
    mcube->faces.push_back(gp::Face(5, 7, 6));

    mcube->faces.push_back(gp::Face(2, 6, 3));
    mcube->faces.push_back(gp::Face(3, 6, 7));

    mcube->faces.push_back(gp::Face(0, 4, 2));
    mcube->faces.push_back(gp::Face(2, 4, 6));

    mcube->faces.push_back(gp::Face(1, 3, 5));
    mcube->faces.push_back(gp::Face(3, 7, 5));

    gp::Object cube(mcube);

    cube.position = {0, 0, 6};


    struct winsize w;
    int width;
    int height;
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
    {
        width = w.ws_col;
        height = w.ws_row;
    }

    gp::Camera cam;
    cam.aspect = static_cast<float>(width)/height*0.5f;

    gp::asc::Window window(width, height);

    window.init();

    for(int i = 0; i < 20; ++i)
    {
        window.clear();

        cube.pitch += std::numbers::pi/5;
        cube.roll += std::numbers::pi/5;
        // cube.position.z = sin(i*std::numbers::pi/2);

        std::vector<gp::Triangle> tarr = gp::Projection::projectObject(cube, cam);

        for(gp::Triangle t : tarr)
        {
            gp::Triangle2D t2;

            t2.a = gp::Vertex2D(window.toScreen(t.a.position), {255,255,255}, t.a.position.z);
            t2.b = gp::Vertex2D(window.toScreen(t.b.position), {255,255,255}, t.b.position.z);
            t2.c = gp::Vertex2D(window.toScreen(t.c.position), {255,255,255}, t.c.position.z);

            window.drawTriangle(t2);
        }

        window.display();
        sleep(1);
    }
    window.close();

	return 0;
}
