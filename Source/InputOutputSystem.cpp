#include "InputOutputSystem.hpp"


InputOutputSystem::InputOutputSystem(std::unique_ptr<Core> core) 
    : _core(std::move(core))
{}
