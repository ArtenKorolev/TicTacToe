#include "Core.hpp"


Core::Core() 
    : _field(FieldInteractor(Field()))
{}

void Core::userStep(int x, int y) {
    _field.setCross(x, y);
}

void Core::computerStep() {
    auto emptyCells = _field.getEmptyCells();

    if (emptyCells.empty()) {
        throw std::runtime_error("Нет пустых клеток");
    }

    int randomIndex = utils::getRandomNumberBetween(0, emptyCells.size() - 1);
    auto randomCell = emptyCells[randomIndex];
    _field.setZero(randomCell.first, randomCell.second);
}

bool Core::checkWinPosition() {
    return _field.checkWinPosition();
}

bool Core::checkDrawPosition() {
   return _field.checkDrawPosition();
}
