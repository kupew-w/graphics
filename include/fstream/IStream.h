#pragma once

#include "objects/Object.h"
#include <memory>

namespace gp 
{

struct IStream
{
    virtual std::shared_ptr<Mesh> read(const std::string& path_to_file) noexcept(false) = 0;
};

}
