#include "render/ASCII/render/Color.h"
#include <algorithm>
#include <cmath>

using namespace gp;
using namespace asc;

char AsciiColor::cts(Color c)
{
    char s[17] = {' ','.',':','!','/','r','(','l','1','Z','4','H','9','W','8','$','@'};

    float q = (c.r*0.21f+c.g*0.72f+c.b*0.07f)/255.0f;
    q = std::clamp(q, 0.0f, 1.0f);

    if(!std::isfinite(q)) return 'X';

    int i = q*16.0f;

    return s[i];
}
