#include "Bot.hpp"


void Bot::makeStep(FieldInteractor &field) {
    auto emptyCells = field.getEmptyCellsCoordinates();

    if (emptyCells.empty()) {
        throw std::runtime_error("Нет доступных клеток для хода");
    }

    int randomIndex = utils::getRandomNumberBetween(0, static_cast<int>(emptyCells.size()) - 1);
    Coordinates randomCell = emptyCells[randomIndex];
    
    field.setCross(randomCell);
}
