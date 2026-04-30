
#include "render/Projection.h"
#include "geomtery/Triangle.h"
#include "objects/Object.h"
#include <vector>

using namespace gp;

std::vector<Triangle> Projection::projectObject(const Object& obj, const Camera& cam)
{
    std::vector<Triangle> out;

    for (gp::Face f : obj.mesh->faces)
    {
        // gp::Face f = cube.mesh->faces[i];

        gp::Triangle t;

        t.a = gp::Vertex(obj.mesh->vertices[f.a]);
        t.b = gp::Vertex(obj.mesh->vertices[f.b]);
        t.c = gp::Vertex(obj.mesh->vertices[f.c]);

        gp::Vec4 a = gp::Vec4(t.a.position); 
        gp::Vec4 b = gp::Vec4(t.b.position);
        gp::Vec4 c = gp::Vec4(t.c.position);

        //gp::Vec4 a, b, c;

        gp::Mat4 proj = cam.projectionMatrix();
        gp::Mat4 view = cam.viewMatrix();
        gp::Mat4 mod = obj.modelMatrix();

        a = mod * a;
        b = mod * b;
        c = mod * c;

        a = view * a;
        b = view * b;
        c = view * c;

        a = proj * a;
        b = proj * b;
        c = proj * c;

        if(a.w < 0.1f || b.w < 0.1f || c.w < 0.1f) continue;

        gp::Vec3 ndcA = a/a.w;
        gp::Vec3 ndcB = b/b.w;
        gp::Vec3 ndcC = c/c.w;

        t.a.position = a/a.w;
        t.b.position = b/b.w;
        t.c.position = c/c.w;

        out.push_back(t);
    }

    return out;
}
