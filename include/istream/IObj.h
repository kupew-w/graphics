#pragma once

#include "istream/IStream.h"
#include "objects/Object.h"
#include <memory>
#include <string>
namespace gp 
{

struct IObj : IStream
{
    std::shared_ptr<Mesh> read(const std::string& path_to_file) noexcept(false) override final;
};

}
