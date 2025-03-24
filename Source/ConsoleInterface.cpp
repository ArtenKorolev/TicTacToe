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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void ConsoleInterface::_printField() {
    std::cout << "   ";
    for (int j = 0; j < FIELD_WIDTH; ++j) {
        std::cout << " " << j + 1 << "  ";
    }
    std::cout << '\n';

    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        std::cout << "   ";
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            std::cout << "+---";
        }
        std::cout << "+\n";

        std::cout << " " << i + 1 << " ";
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            auto cell = _field.getCellByCoordinates(Coordinates{j, i});
            std::cout << "| " << _getCellCharByState(cell.state) << " ";
        }
        std::cout << "|\n";
    }

    std::cout << "   ";
    for (int j = 0; j < FIELD_WIDTH; ++j) {
        std::cout << "+---";
    }
    std::cout << "+\n";
}

std::string ConsoleInterface::_getCellCharByState(CellState state) {
    switch (state) {
        case CellState::EMPTY:
            return " ";
        case CellState::ZERO:
            return "O";
        case CellState::CROSS:
            return "X";
    }
}

void ConsoleInterface::_userStep() {
    int x, y;
    std::cout << "Введите координаты клетки на которую хотите походить (y x): ";

    while (true) {
        std::cin >> y >> x;
        try {
            _core.userStep(Coordinates{x - 1, y - 1});
            break;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << ". Попробуйте снова: ";
        }
    }
}
