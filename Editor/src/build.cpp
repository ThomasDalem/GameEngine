#include "build.hpp"
#include <filesystem>

void buildProject()
{
    std::filesystem::copy("../build/Runtime/runtime", "../GameExample/runtime", std::filesystem::copy_options::update_existing);
    std::filesystem::copy("../build/Engine/libgengine.so", "../GameExample/lib/libgengine.so", std::filesystem::copy_options::update_existing);
}
