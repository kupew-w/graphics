#include "fstream/FObj.h"
#include "geomtery/Face.h"
#include "geomtery/Vertex.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
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
        std::istringstream ss(line);
        std::string type;
        ss >> type;

        if(type == "v")
        {
            Vec3 v;
            ss >> v.x >> v.y >> v.z;
            out->vertices.push_back({v, {255, 255, 255}});//FIXME color
        }         
        else if(type == "f")
        {
            Face f;
            ss >> f.a >> f.b >> f.c;
            --f.a;
            --f.b;
            --f.c;
            out->faces.push_back(f);
        }
    }

    return out;
}
