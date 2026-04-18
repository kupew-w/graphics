#pragma once

#include "fstream/IStream.h"
#include "objects/Object.h"
#include <memory>
#include <string>
namespace gp 
{

struct FObj : IStream
{
    std::shared_ptr<Mesh> read(const std::string& path_to_file) noexcept(false) override final;
};

}
