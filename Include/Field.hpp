#ifndef FIELD_HPP
#define FIELD_HPP

#include <array>
#include <vector>
#include "Constants.hpp"
#include "Cell.hpp"


class Field {
public:
    Field() = default;
    void setCross(int x, int y);
    void setZero(int x, int y);
    std::vector<std::pair<int, int>> getEmptyCells();
    CellState getCellState(int x, int y); 
private:
    Cell &_getCellByCoordinates(int x, int y);
    std::array<Cell, FIELD_SIZE> _field;
};


#endif // FIELD_HPP
