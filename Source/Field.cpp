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
    // Проверка строк
    for (int y = 0; y < FIELD_HEIGHT; ++y) {
        CellState firstCellState = _field.getCellByCoordinates({0, y}).state;
        if (firstCellState != CellState::EMPTY) {
            bool rowWin = true;
            for (int x = 1; x < FIELD_WIDTH; ++x) {
                if (_field.getCellByCoordinates({x, y}).state != firstCellState) {
                    rowWin = false;
                    break;
                }
            }
            if (rowWin) {
                return true;
            }
        }
    }

    // Проверка столбцов
    for (int x = 0; x < FIELD_WIDTH; ++x) {
        CellState firstCellState = _field.getCellByCoordinates({x, 0}).state;
        if (firstCellState != CellState::EMPTY) {
            bool colWin = true;
            for (int y = 1; y < FIELD_HEIGHT; ++y) {
                if (_field.getCellByCoordinates({x, y}).state != firstCellState) {
                    colWin = false;
                    break;
                }
            }
            if (colWin) {
                return true;
            }
        }
    }

    // Проверка главной диагонали
    CellState firstDiagonalState = _field.getCellByCoordinates({0, 0}).state;
    if (firstDiagonalState != CellState::EMPTY) {
        bool diagonalWin = true;
        for (int i = 1; i < std::min(FIELD_WIDTH, FIELD_HEIGHT); ++i) {
            if (_field.getCellByCoordinates({i, i}).state != firstDiagonalState) {
                diagonalWin = false;
                break;
            }
        }
        if (diagonalWin) {
            return true;
        }
    }

    // Проверка побочной диагонали
    CellState secondDiagonalState = _field.getCellByCoordinates({0, FIELD_HEIGHT - 1}).state;
    if (secondDiagonalState != CellState::EMPTY) {
        bool diagonalWin = true;
        for (int i = 1; i < std::min(FIELD_WIDTH, FIELD_HEIGHT); ++i) {
            if (_field.getCellByCoordinates({i, FIELD_HEIGHT - 1 - i}).state != secondDiagonalState) {
                diagonalWin = false;
                break;
            }
        }
        if (diagonalWin) {
            return true;
        }
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
