#ifndef CELL_HPP
#define CELL_HPP


enum class CellState {
    EMPTY,
    CROSS,
    ZERO
};


struct Cell {
    CellState state = CellState::EMPTY;
};


#endif // CELL_HPP
