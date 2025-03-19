#ifndef INPUTOUTPUTSYSTEM_HPP
#define INPUTOUTPUTSYSTEM_HPP

#include "Core.hpp"
#include "memory"


class InputOutputSystem {
public:
    InputOutputSystem(std::unique_ptr<Core> core);
    virtual ~InputOutputSystem() = default;
    virtual void gameLoop() = 0;
protected:
    const std::unique_ptr<Core> _core;
};


#endif // INPUTOUTPUTSYSTEM_HPP
