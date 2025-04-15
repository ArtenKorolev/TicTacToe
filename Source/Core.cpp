#include "Core.hpp"


Core::Core(FieldInteractor &field, std::unique_ptr<Bot> bot) 
    : _field(field), _bot(std::move(bot))
{}

void Core::userStep(Coordinates coordinates) {
    if (!_field.isCellEmpty(coordinates)) {
        throw std::runtime_error("Клетка уже занята");
    }

    _field.setCross(coordinates);
}

void Core::computerStep() {
    _bot->makeStep(_field);
}

bool Core::checkWinPosition() {
    return _field.checkWinPosition();
}

bool Core::checkDrawPosition() {
   return _field.checkDrawPosition();
}
