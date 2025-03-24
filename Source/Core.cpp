#include "Core.hpp"


Core::Core(FieldInteractor &field) 
    : _field(field)
{}

void Core::userStep(Coordinates coordinates) {
    if (!_field.isCellEmpty(coordinates)) {
        throw std::runtime_error("Клетка уже занята");
    }

    _field.setCross(coordinates);
}

void Core::computerStep() {
    auto emptyCells = _field.getEmptyCellsCoordinates();

    if (emptyCells.empty()) {
        throw std::runtime_error("Нет пустых клеток");
    }

    int randomIndex = utils::getRandomNumberBetween(0, emptyCells.size() - 1);
    auto randomCellCoordinates = emptyCells[randomIndex];
    _field.setZero(randomCellCoordinates);
}

bool Core::checkWinPosition() {
    return _field.checkWinPosition();
}

bool Core::checkDrawPosition() {
   return _field.checkDrawPosition();
}
