#include "Field.hpp"


Cell &Field::getCellByCoordinates(int x, int y) {
    _validateCoordinatesToSetValue(x, y);
    return _field[y * FIELD_WIDTH + x];
}

void Field::_validateCoordinatesToSetValue(int x, int y) {
    if (x < 0 || x >= FIELD_WIDTH || y < 0 || y >= FIELD_HEIGHT) {
        throw std::out_of_range("Неверная позиция клетки");
    }
    if (getCellByCoordinates(x, y).state != CellState::EMPTY) {
        throw std::invalid_argument("Клетка занята");
    }
}

std::vector<std::pair<int, int>> Field::getEmptyCells() {
    std::vector<std::pair<int, int>> emptyCells;

    for (int y = 0; y < FIELD_HEIGHT; ++y) {
        for (int x = 0; x < FIELD_WIDTH; ++x) {
            if (getCellByCoordinates(x, y).state == CellState::EMPTY) {
                emptyCells.push_back(std::make_pair(x, y));
            }
        }
    }

    return emptyCells;
}

FieldInteractor::FieldInteractor(Field &field)
    : _field(field)
{}

FieldInteractor::FieldInteractor(Field &&field)
    : _field(std::move(field))
{}

void FieldInteractor::setZero(int x, int y) {
    _field.getCellByCoordinates(x, y).state = CellState::ZERO;
}

void FieldInteractor::setCross(int x, int y) {
    _field.getCellByCoordinates(x, y).state = CellState::CROSS;
}

bool FieldInteractor::checkWinPosition() {
    for (int i = 0; i < FIELD_WIDTH; ++i) {
        if (_field.getCellByCoordinates(i, 0).state == _field.getCellByCoordinates(i, 1).state &&
            _field.getCellByCoordinates(i, 1).state == _field.getCellByCoordinates(i, 2).state &&
            _field.getCellByCoordinates(i, 0).state != CellState::EMPTY) {
            return true;
        }
    }

    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        if (_field.getCellByCoordinates(0, i).state == _field.getCellByCoordinates(1, i).state &&
            _field.getCellByCoordinates(1, i).state == _field.getCellByCoordinates(2, i).state &&
            _field.getCellByCoordinates(0, i).state != CellState::EMPTY) {
            return true;
        }
    }

    if (_field.getCellByCoordinates(0, 0).state == _field.getCellByCoordinates(1, 1).state &&
        _field.getCellByCoordinates(1, 1).state == _field.getCellByCoordinates(2, 2).state &&
        _field.getCellByCoordinates(0, 0).state != CellState::EMPTY) {
        return true;
    }

    if (_field.getCellByCoordinates(0, 2).state == _field.getCellByCoordinates(1, 1).state &&
        _field.getCellByCoordinates(1, 1).state == _field.getCellByCoordinates(2, 0).state &&
        _field.getCellByCoordinates(0, 2).state != CellState::EMPTY) {
        return true;
    }

    return false;
}

bool FieldInteractor::checkDrawPosition() {
    if (checkWinPosition()) {
        return false;
    }

    return _field.getEmptyCells().empty();
}

std::vector<std::pair<int, int>> FieldInteractor::getEmptyCells() {
    return std::move(_field.getEmptyCells());
}
