#include "Core.hpp"


Core::Core() 
    : _field(Field())
{}

void Core::userStep(int x, int y) {
    _field.setCross(x, y);
}

void Core::computerStep() {
    auto emptyCells = _field.getEmptyCells();

    if (emptyCells.empty()) {
        throw std::runtime_error("Нет пустых клеток");
    }

    auto randomCell = emptyCells[utils::getRandomNumberBetween(0, emptyCells.size() - 1)];
    _field.setZero(randomCell.first, randomCell.second);
}

bool Core::checkWinPosition() {
    return false;
}

bool Core::checkDrawPosition() {
    return false;
}
