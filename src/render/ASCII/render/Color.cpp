#include "render/ASCII/render/Color.h"

using namespace gp;
using namespace asc;

char AsciiColor::cts(Color c)
{
    char s[17] = {' ','.',':','!','/','r','(','l','1','Z','4','H','9','W','8','$','@'};

    int i = (c.r*0.21+c.g*0.72+c.b*0.07)/255.0*16;

    return s[i];
}
