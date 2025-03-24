#include "Field.hpp"


Cell &Field::getCellByCoordinates(Coordinates coordinates) {
    _validateCoordinatesToSetValue(coordinates);
    return _field[coordinates.y * FIELD_WIDTH + coordinates.x];
}

void Field::_validateCoordinatesToSetValue(Coordinates coordinates) {
    if (coordinates.x < 0 || coordinates.x >= FIELD_WIDTH || coordinates.y < 0 || coordinates.y >= FIELD_HEIGHT) {
        throw std::out_of_range("Неверная позиция клетки");
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

void FieldInteractor::setZero(Coordinates coordinates) {
    _field.getCellByCoordinates(coordinates).state = CellState::ZERO;
}

void FieldInteractor::setCross(Coordinates coordinates) {
    _field.getCellByCoordinates(coordinates).state = CellState::CROSS;
}

bool FieldInteractor::checkWinPosition() {
    auto checkLine = [&](std::vector<Coordinates> line) {
        CellState firstState = _field.getCellByCoordinates(line[0]).state;
        if (firstState == CellState::EMPTY) {
            return false;
        }
        for (const auto &coord : line) {
            if (_field.getCellByCoordinates(coord).state != firstState) {
                return false;
            }
        }
        return true;
    };

    for (int y = 0; y < FIELD_HEIGHT; ++y) {
        std::vector<Coordinates> row;
        for (int x = 0; x < FIELD_WIDTH; ++x) {
            row.push_back(Coordinates{x, y});
        }
        if (checkLine(row)) {
            return true;
        }
    }

    for (int x = 0; x < FIELD_WIDTH; ++x) {
        std::vector<Coordinates> column;
        for (int y = 0; y < FIELD_HEIGHT; ++y) {
            column.push_back(Coordinates{x, y});
        }
        if (checkLine(column)) {
            return true;
        }
    }

    std::vector<Coordinates> mainDiagonal;
    for (int i = 0; i < std::min(FIELD_WIDTH, FIELD_HEIGHT); ++i) {
        mainDiagonal.push_back(Coordinates{i, i});
    }
    if (checkLine(mainDiagonal)) {
        return true;
    }

    std::vector<Coordinates> antiDiagonal;
    for (int i = 0; i < std::min(FIELD_WIDTH, FIELD_HEIGHT); ++i) {
        antiDiagonal.push_back(Coordinates{i, FIELD_HEIGHT - 1 - i});
    }
    if (checkLine(antiDiagonal)) {
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

Cell FieldInteractor::getCellByCoordinates(Coordinates coordinates) {
    return _field.getCellByCoordinates(coordinates);
}

bool FieldInteractor::isCellEmpty(Coordinates coordinates) {
    return getCellByCoordinates(coordinates).state == CellState::EMPTY;
}
