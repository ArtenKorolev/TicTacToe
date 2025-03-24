#include "ConsoleInterface.hpp"


ConsoleInterface::ConsoleInterface(FieldInteractor &field)
    : IOInterface(field), _core(Core(field))
{}

void ConsoleInterface::gameLoop() {
    while (true) {
        _printField();
        _userStep();
        if (_core.checkWinPosition()) {
            _printField();
            std::cout << "Вы победили!" << std::endl;
            break;
        }
        if (_core.checkDrawPosition()) {
            _printField();
            std::cout << "Ничья!" << std::endl;
            break;
        }
        _core.computerStep();
        if (_core.checkWinPosition()) {
            _printField();
            std::cout << "Вы проиграли!" << std::endl;
            break;
        }
    }
}

void ConsoleInterface::_printField() {
    // pass
}

void ConsoleInterface::_userStep() {
    int x, y;
    std::cout << "Введите координаты клетки на которую хотите походить: ";
    std::cin >> x >> y;
    _core.userStep(Coordinates{x, y});
}
