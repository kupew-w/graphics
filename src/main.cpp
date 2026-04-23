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
    
    mcube->vertices.push_back(gp::Vertex({3, 3, 3}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({3, 3, 0}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({3, 0, 3}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({3, 0, 0}, {255,255,255}));

    mcube->vertices.push_back(gp::Vertex({0, 3, 3}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({0, 3, 0}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({0, 0, 3}, {255,255,255}));
    mcube->vertices.push_back(gp::Vertex({0, 0, 0}, {255,255,255}));


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
    cam.aspect = static_cast<float>(width)/height*0.5f;

    gp::asc::Window window(width, height);


    window.init();
    window.clear();

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

        a = mod * gp::Vec4(t.a.position);
        b = mod * gp::Vec4(t.b.position);
        c = mod * gp::Vec4(t.c.position);

        std::cout << a.x << " " << a.y << " " << a.z << " " << a.w << " :vec4 after mod\n";
        std::cout << b.x << " " << b.y << " " << b.z << " " << b.w << " :vec4 bfter mod\n";
        std::cout << c.x << " " << c.y << " " << c.z << " " << c.w << " :vec4 cfter mod\n";
        
        a = view * a;
        b = view * b;
        c = view * c;

        a = proj * a;
        b = proj * b;
        c = proj * c;

        gp::Triangle2D t2;

        // std::cout << a.w << "\t";
        
        if(a.w < 0.1f || b.w < 0.1f || c.w < 0.1f) continue;

        gp::Vec3 ndcA = a/a.w;
        gp::Vec3 ndcB = b/b.w;
        gp::Vec3 ndcC = c/c.w;

        

        std::cout << ndcA.x << " " << ndcA.y << " " << ndcA.z << " :vec3 after division ay w\n";
        std::cout << ndcB.x << " " << ndcB.y << " " << ndcB.z << " :vec3 Bfter division by w\n";
        std::cout << ndcC.x << " " << ndcC.y << " " << ndcC.z << " :vec3 Cfter division Cy w\n";

        // std::cout << ndcA.x << " " << ndcA.y << " " << ndcA.z << "\n";
        // std::cout << ndcB.x << " " << ndcB.y << " " << ndcB.z << "\n";

        t2.a = gp::Vertex2D(window.toScreen(ndcA), {255,255,255}, ndcA.z);
        t2.b = gp::Vertex2D(window.toScreen(ndcB), {255,255,255}, ndcB.z);
        t2.c = gp::Vertex2D(window.toScreen(ndcC), {255,255,255}, ndcC.z);

        std::cout << t2.a.position.x << " " << t2.a.position.y << " :triangle\n";
        std::cout << t2.b.position.x << " " << t2.b.position.y << " :tribngle\n";
        std::cout << t2.c.position.x << " " << t2.c.position.y << " :tricngle\n";

        window.drawTriangle(t2);
    }*/

    // for (gp::Face f : cube.mesh->faces)
    for(int i = 8; i < 10; ++i)
    {
        gp::Face f = cube.mesh->faces[i];

        gp::Triangle t;

        t.a = gp::Vertex(cube.mesh->vertices[f.a]);
        t.b = gp::Vertex(cube.mesh->vertices[f.b]);
        t.c = gp::Vertex(cube.mesh->vertices[f.c]);

        // gp::Vec4 a = gp::Vec4(t.a.position); 
        // gp::Vec4 b = gp::Vec4(t.b.position);
        // gp::Vec4 c = gp::Vec4(t.c.position);
        
        gp::Vec4 a, b, c;

        gp::Mat4 proj = cam.projectionMatrix();
        gp::Mat4 view = cam.viewMatrix();
        gp::Mat4 mod = cube.modelMatrix();

        std::cout << t.b.position.x << " " << t.b.position.y << " " << t.b.position.z << " :tribngle\n";
        std::cout << cube.scale.x << " " << cube.scale.y << " " << cube.scale.z << " :scale\n";

        //a = mod * a;
        // b = mod * b;
        // c = mod * c;


        // a = view * a;
        // b = view * a;
        // c = view * a;
        
        a = view*gp::Vec4(t.a.position);
        b = view*gp::Vec4(t.b.position);
        c = view*gp::Vec4(t.c.position);

        a = proj * a;
        b = proj * b;
        c = proj * c;

        std::cout << a.x << " " << a.y << " " << a.z << " " << a.w << " :vec4 after proj\n";
        std::cout << b.x << " " << b.y << " " << b.z << " " << b.w << " :vec4 bfter proj\n";
        std::cout << c.x << " " << c.y << " " << c.z << " " << c.w << " :vec4 cfter proj\n";

        if(a.w < 0.1f || b.w < 0.1f || c.w < 0.1f) continue;

        gp::Vec3 ndcA = a/a.w;
        gp::Vec3 ndcB = b/b.w;
        gp::Vec3 ndcC = c/c.w;

        std::cout << ndcA.x << " " << ndcA.y << " " << ndcA.z << " :vec3 after division ay w\n";
        std::cout << ndcB.x << " " << ndcB.y << " " << ndcB.z << " :vec3 Bfter division by w\n";
        std::cout << ndcC.x << " " << ndcC.y << " " << ndcC.z << " :vec3 Cfter division Cy w\n";

        gp::Triangle2D t2;

        t2.a = gp::Vertex2D(window.toScreen(ndcA), {255,255,255}, ndcA.z);
        t2.b = gp::Vertex2D(window.toScreen(ndcB), {255,255,255}, ndcB.z);
        t2.c = gp::Vertex2D(window.toScreen(ndcC), {255,255,255}, ndcC.z);

        std::cout << t2.a.position.x << " " << t2.a.position.y << " :triangle\n";
        std::cout << t2.b.position.x << " " << t2.b.position.y << " :tribngle\n";
        std::cout << t2.c.position.x << " " << t2.c.position.y << " :tricngle\n";

        window.drawTriangle(t2);
    }

    std::cout << "qwe\n";
    window.display();
    //}
    sleep(5);
    window.close();

	return 0;
}
