#include "fstream/FObj.h"
#include "geomtery/Triangle.h"
#include "geomtery/Vertex.h"
#include "objects/Object.h"
#include <cstdio>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace gp;

std::shared_ptr<Mesh> FObj::read(const std::string& ptf) 
{
    std::ifstream file(ptf);

    if(!file.is_open())
        throw std::runtime_error("Cannot open file: " + ptf);

    std::shared_ptr<Mesh> out = std::make_shared<Mesh>();
    std::vector<Vertex> vertexes;
    
    std::string line;

    while(std::getline(file, line))
    {
        if(line.size() < 2) continue; 

        if(line[0] == 'v' && line[1] == ' ')
        {
            Vec3 v;
            std::scanf(line.c_str(), "v %f %f %f", &v.x, &v.y, &v.z);
            Vertex ver = {v, {255, 255, 255}}; //FIXME
            vertexes.push_back(ver);
        }         
        else if(line [0] == 'f')
        {
            Triangle t;
            int a, b, c;
            std::scanf(line.c_str(), "f %f %f %f", &a, &b, &c);
            t.a = vertexes[a];
            t.b = vertexes[b];
            t.c = vertexes[c];
            out->triangles.push_back(t);
        }
    }

    return out;
}
