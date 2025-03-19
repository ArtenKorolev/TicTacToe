#include "Field.hpp"


void Field::setCross(int x, int y) {
    _getCellByCoordinates(x, y).state = CellState::CROSS;
}

void Field::setZero(int x, int y) {
    _getCellByCoordinates(x, y).state = CellState::ZERO;
}

CellState Field::getCellState(int x, int y) {
    return _getCellByCoordinates(x, y).state;
}

Cell &Field::_getCellByCoordinates(int x, int y) {
    return _field[y * FIELD_WIDTH + x];
}
