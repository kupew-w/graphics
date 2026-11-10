#pragma once

#include "objects/Camera.h"
#include "render/Viewport.h"
#include <memory>
namespace gp 
{

class IRender
{
protected:
    std::shared_ptr<gp::Camera> cam = nullptr;
    Viewport view = Viewport(0, 0, 0, 0);

public:
    virtual void clear() = 0;
    virtual void display() = 0;

    virtual void setCamera(std::shared_ptr<gp::Camera> cam) { this->cam = cam; }
    virtual void setViewport(gp::Viewport v) { view = v; };

    IRender() = default;

    IRender(IRender&&) = default;
    IRender& operator=(IRender&&) = default;

    IRender(const IRender&) = delete;
    IRender operator=(const IRender&) = delete;
    
    virtual ~IRender() = default;
};

}
