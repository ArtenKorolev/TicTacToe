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
    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            auto cell = _field.getCellByCoordinates(Coordinates{j, i});
            switch (cell.state) {
                case CellState::EMPTY:
                    std::cout << " ";
                    break;
                case CellState::ZERO:
                    std::cout << "O";
                    break;
                case CellState::CROSS:
                    std::cout << "X";
                    break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void ConsoleInterface::_userStep() {
    int x, y;
    std::cout << "Введите координаты клетки на которую хотите походить: ";
    std::cin >> x >> y;
    _core.userStep(Coordinates{x, y});
}
