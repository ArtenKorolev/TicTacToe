#ifndef FIELD_HPP
#define FIELD_HPP

#include <array>
#include <vector>
#include <stdexcept>
#include "Constants.hpp"
#include "Cell.hpp"


struct Coordinates {
    int x, y;
};


class Field {
public:
    Field() = default;
    Cell &getCellByCoordinates(Coordinates coordinates);
    std::vector<Coordinates> getEmptyCellsCoordinates();
private:
    void _validateCoordinatesToSetValue(Coordinates coordinates);
    std::array<Cell, FIELD_SIZE> _field;
};


class FieldInteractor {
public:
    FieldInteractor(Field &field);
    void setZero(Coordinates coordinates);
    void setCross(Coordinates coordinates);
    bool checkWinPosition();
    bool checkDrawPosition();
    std::vector<Coordinates> getEmptyCellsCoordinates();
private:
    Field &_field;
};


#endif // FIELD_HPP
