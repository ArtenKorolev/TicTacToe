#ifndef FIELD_HPP
#define FIELD_HPP

#include <array>
#include <vector>
#include <stdexcept>
#include "Constants.hpp"
#include "Cell.hpp"


class Field {
public:
    Field() = default;
    Cell &getCellByCoordinates(int x, int y);
    std::array<Cell, FIELD_SIZE> &getEntireField();
    std::vector<std::pair<int, int>> getEmptyCells();
private:
    void _validateCoordinatesToSetValue(int x, int y);
    std::array<Cell, FIELD_SIZE> _field;
};


class FieldInteractor {
public:
    FieldInteractor(Field &field);
    FieldInteractor(Field &&field);
    void setZero(int x, int y);
    void setCross(int x, int y);
    bool checkWinPosition();
    bool checkDrawPosition();
    std::vector<std::pair<int, int>> getEmptyCells();
private:
    Field _field;
};


#endif // FIELD_HPP
