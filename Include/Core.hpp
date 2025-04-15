#ifndef CORE_HPP
#define CORE_HPP

#include <stdexcept>
#include <memory>
#include "Utils.hpp"
#include "Field.hpp"
#include "Bot.hpp"


class Core {
public:
    Core(FieldInteractor &field, std::unique_ptr<Bot> bot);
    void userStep(Coordinates coordinates);
    void computerStep();
    bool checkWinPosition();
    bool checkDrawPosition();
private:
    FieldInteractor &_field;
    std::unique_ptr<Bot> _bot;
};


#endif // CORE_HPP
