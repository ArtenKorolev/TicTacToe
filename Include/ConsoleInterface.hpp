#ifndef CONSOLEINTERFACE_HPP
#define CONSOLEINTERFACE_HPP

#include "IOInterface.hpp"
#include "Constants.hpp"
#include "Logger.hpp"
#include "Bot.hpp"
#include <iostream>


class ConsoleInterface : public IOInterface {
public:
    ConsoleInterface(FieldInteractor &field);
    void gameLoop() override;
private:
    void _printField();
    std::string _getCellCharByState(CellState state);
    void _userStep();
    Core _core;
    Bot _bot;
};


#endif // CONSOLEINTERFACE_HPP
