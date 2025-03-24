#include "Field.hpp"


Cell &Field::getCellByCoordinates(Coordinates coordinates) {
    _validateCoordinatesToSetValue(coordinates);
    return _field[coordinates.y * FIELD_WIDTH + coordinates.x];
}

void Field::_validateCoordinatesToSetValue(Coordinates coordinates) {
    if (coordinates.x < 0 || coordinates.x >= FIELD_WIDTH || coordinates.y < 0 || coordinates.y >= FIELD_HEIGHT) {
        throw std::out_of_range("Неверная позиция клетки");
    }
    if (getCellByCoordinates(coordinates).state != CellState::EMPTY) {
        throw std::invalid_argument("Клетка занята");
    }
}

std::vector<Coordinates> Field::getEmptyCellsCoordinates() {
    std::vector<Coordinates> emptyCellsCoordinates;

    for (int y = 0; y < FIELD_HEIGHT; ++y) {
        for (int x = 0; x < FIELD_WIDTH; ++x) {
            if (getCellByCoordinates(Coordinates{x, y}).state == CellState::EMPTY) {
                emptyCellsCoordinates.push_back(std::move(Coordinates{x, y}));
            }
        }
    }

    return emptyCellsCoordinates;
}

FieldInteractor::FieldInteractor(Field &field)
    : _field(field)
{}

FieldInteractor::FieldInteractor(Field &&field)
    : _field(std::move(field))
{}

void FieldInteractor::setZero(Coordinates coordinates) {
    _field.getCellByCoordinates(coordinates).state = CellState::ZERO;
}

void FieldInteractor::setCross(Coordinates coordinates) {
    _field.getCellByCoordinates(coordinates).state = CellState::CROSS;
}

bool FieldInteractor::checkWinPosition() {
    for (int x = 0; x < FIELD_WIDTH; ++x) {
        if (_field.getCellByCoordinates(Coordinates{x, 0}).state == _field.getCellByCoordinates(Coordinates{x, 1}).state &&
            _field.getCellByCoordinates(Coordinates{x, 1}).state == _field.getCellByCoordinates(Coordinates{x, 2}).state &&
            _field.getCellByCoordinates(Coordinates{x, 0}).state != CellState::EMPTY) {
            return true;
        }
    }

    for (int y = 0; y < FIELD_HEIGHT; ++y) {
        if (_field.getCellByCoordinates(Coordinates{0, y}).state == _field.getCellByCoordinates(Coordinates{1, y}).state &&
            _field.getCellByCoordinates(Coordinates{1, y}).state == _field.getCellByCoordinates(Coordinates{2, y}).state &&
            _field.getCellByCoordinates(Coordinates{0, y}).state != CellState::EMPTY) {
            return true;
        }
    }

    if (_field.getCellByCoordinates(Coordinates{0, 0}).state == _field.getCellByCoordinates(Coordinates{1, 1}).state &&
        _field.getCellByCoordinates(Coordinates{1, 1}).state == _field.getCellByCoordinates(Coordinates{2, 2}).state &&
        _field.getCellByCoordinates(Coordinates{0, 0}).state != CellState::EMPTY) {
        return true;
    }

    if (_field.getCellByCoordinates(Coordinates{0, 2}).state == _field.getCellByCoordinates(Coordinates{1, 1}).state &&
        _field.getCellByCoordinates(Coordinates{1, 1}).state == _field.getCellByCoordinates(Coordinates{2, 0}).state &&
        _field.getCellByCoordinates(Coordinates{0, 2}).state != CellState::EMPTY) {
        return true;
    }

    return false;
}

bool FieldInteractor::checkDrawPosition() {
    if (checkWinPosition()) {
        return false;
    }

    return _field.getEmptyCellsCoordinates().empty();
}

std::vector<Coordinates> FieldInteractor::getEmptyCellsCoordinates() {
    return std::move(_field.getEmptyCellsCoordinates());
}
