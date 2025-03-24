#ifndef CONSOLEINTERFACE_HPP
#define CONSOLEINTERFACE_HPP


#include "IOInterface.hpp"
#include <iostream>


class ConsoleInterface : public IOInterface {
public:
    ConsoleInterface(FieldInteractor &field);
    void gameLoop() override;
private:
    void _printField();
    void _userStep();
    Core _core;
};


#endif // CONSOLEINTERFACE_HPP
