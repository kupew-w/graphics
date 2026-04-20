#include "fstream/FObj.h"
#include "geomtery/Face.h"
#include "geomtery/Triagle2D.h"
#include "geomtery/Triangle.h"
#include "geomtery/Vertex.h"
#include "geomtery/Vertex2D.h"
#include "math/Mat4.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include "objects/Camera.h"
#include "objects/Object.h"
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

    std::shared_ptr<gp::Mesh> mcube = std::make_shared<gp::Mesh>();
    
    mcube->vertices.push_back(gp::Vertex({1, 1, 1}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({1, 1, -1}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({1, -1, 1}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({1, -1, -1}, {255,255,255}));

    mcube->vertices.push_back(gp::Vertex({-1, 1, 1}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({-1, 1, -1}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({-1, -1, 1}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({-1, -1, -1}, {255,255,255}));


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
    mcube->faces.push_back(gp::Face(4, 7, 5));

    gp::Object cube(mcube);

    cube.position = {0, 0, 0};


    struct winsize w;
    int width;
    int height;
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
    {
        width = w.ws_col;
        height = w.ws_row;
    }

    gp::Camera cam;
    cam.aspect = static_cast<float>(width)/height;

    gp::asc::Window window(width, height);


    window.init();
    window.clear();
    // window.drawTest();

    /*for(gp::Face f : cube.mesh->faces)
    {
        gp::Triangle t;
        t.a = cube.mesh->vertices[f.a];
        t.b = cube.mesh->vertices[f.b];
        t.c = cube.mesh->vertices[f.c];

        gp::Vec4 a, b, c;

        gp::Mat4 proj = cam.projectionMatrix();
        gp::Mat4 view = cam.viewMatrix();
        gp::Mat4 mod = cube.modelMatrix();
        a = proj * view * mod * gp::Vec4(t.a.position);
        b = proj * view * mod * gp::Vec4(t.b.position);
        c = proj * view * mod * gp::Vec4(t.c.position);

        gp::Triangle2D t2;

        // std::cout << a.w << "\t";

        gp::Vec3 ndcA = a/a.w;
        gp::Vec3 ndcB = b/b.w;
        gp::Vec3 ndcC = c/c.w;

        // std::cout << ndcA.x << " " << ndcA.y << " " << ndcA.z << "\n";
        // std::cout << ndcB.x << " " << ndcB.y << " " << ndcB.z << "\n";

        t2.a = gp::Vertex2D(window.toScreen(ndcA), {255,255,255}, ndcA.z);
        t2.b = gp::Vertex2D(window.toScreen(ndcB), {255,255,255}, ndcB.z);
        t2.c = gp::Vertex2D(window.toScreen(ndcC), {255,255,255}, ndcC.z);

        window.drawTriangle(t2);
    }*/

    // gp::Triangle2D t;
    //
    // t.a = gp::Vertex2D({0, 0}, {255,255,255});
    // t.b = gp::Vertex2D({10, 0}, {255,255,255});
    // t.c = gp::Vertex2D({0, 10}, {255,255,255});
    // window.drawTriangle(t);
    //
    // t.a = gp::Vertex2D({10, 10}, {255,255,255});
    // t.b = gp::Vertex2D({0, 10}, {255,255,255});
    // t.c = gp::Vertex2D({10, 0}, {255,255,255});
    //
    // window.drawTriangle(t);
    //
    /*for(gp::Face f : enderRodMesh->faces)
    {
        gp::Triangle t;
        t.a = enderRodMesh->vertices[f.a];
        t.b = enderRodMesh->vertices[f.b];
        t.c = enderRodMesh->vertices[f.c];

        std::cout << "1test\n";

        t.a.position = cam.projectionMatrix() * cam.viewMatrix() * enderRod.modelMatrix() * t.a.position;
        t.b.position = cam.projectionMatrix() * cam.viewMatrix() * enderRod.modelMatrix() * t.b.position;
        t.c.position = cam.projectionMatrix() * cam.viewMatrix() * enderRod.modelMatrix() * t.c.position;
    }*/

    //std::cout << width << " :w\t" << height << " :h\n";
    
    gp::Triangle t;

    t.a = gp::Vertex({0, 0, 3}, {255,255,255});
    t.b = gp::Vertex({1, 0, 3}, {255,255,255});
    t.b = gp::Vertex({0, 1, 3}, {255,255,255});

    gp::Vec4 a, b, c;

    gp::Mat4 proj = cam.projectionMatrix();
    gp::Mat4 view = cam.viewMatrix();
    a = proj * view * gp::Vec4(t.a.position);
    b = proj * view * gp::Vec4(t.b.position);
    c = proj * view * gp::Vec4(t.c.position);

    gp::Vec3 ndcA = a/a.w;
    gp::Vec3 ndcB = b/b.w;
    gp::Vec3 ndcC = c/c.w;

    gp::Triangle2D t2;

    t2.a = gp::Vertex2D(window.toScreen(ndcA), {255,255,255}, ndcA.z);
    t2.b = gp::Vertex2D(window.toScreen(ndcB), {255,255,255}, ndcB.z);
    t2.c = gp::Vertex2D(window.toScreen(ndcC), {255,255,255}, ndcC.z);

    window.drawTriangle(t2);

    window.display();
    sleep(5);
    window.close();

	return 0;
}
