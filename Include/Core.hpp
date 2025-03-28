#ifndef CORE_HPP
#define CORE_HPP

#include <stdexcept>
#include "Utils.hpp"
#include "Field.hpp"
#include "Bot.hpp"


class Core {
public:
    Core(FieldInteractor &field, Bot &bot);
    void userStep(Coordinates coordinates);
    void computerStep();
    bool checkWinPosition();
    bool checkDrawPosition();
private:
    FieldInteractor &_field;
    Bot &_bot;
};


#endif // CORE_HPP
