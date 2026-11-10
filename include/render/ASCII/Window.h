#pragma once

#include "math/Vec2.h"
#include "math/Vec3.h"
#include "render/IWindow.h"

namespace gp {
namespace asc 
{

class Window : public IWindow
{
public:
    void init() override;
    void close() override;

    Vec2 toScreen(Vec3);
};

}}
