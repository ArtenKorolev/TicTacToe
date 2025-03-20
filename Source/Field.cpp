#include "Field.hpp"


void Field::setCross(int x, int y) {
    _validateCoordinatesToSetValue(x, y);
    _getCellByCoordinates(x, y).state = CellState::CROSS;
}

void Field::setZero(int x, int y) {
    _validateCoordinatesToSetValue(x, y);
    _getCellByCoordinates(x, y).state = CellState::ZERO;
}

void Field::_validateCoordinatesToSetValue(int x, int y) {
    if (x < 0 || x >= FIELD_WIDTH || y < 0 || y >= FIELD_HEIGHT) {
        throw std::out_of_range("Неверная позиция клетки");
    }
    if (getCellState(x, y) != CellState::EMPTY) {
        throw std::invalid_argument("Клетка занята");
    }
}

CellState Field::getCellState(int x, int y) {
    return _getCellByCoordinates(x, y).state;
}

Cell &Field::_getCellByCoordinates(int x, int y) {
    return _field[y * FIELD_WIDTH + x];
}


std::vector<std::pair<int, int>> Field::getEmptyCells() {
    std::vector<std::pair<int, int>> emptyCells;

    for (int y = 0; y < FIELD_HEIGHT; ++y) {
        for (int x = 0; x < FIELD_WIDTH; ++x) {
            if (getCellState(x, y) == CellState::EMPTY) {
                emptyCells.push_back(std::make_pair(x, y));
            }
        }
    }

    return emptyCells;
}
