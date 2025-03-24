#ifndef CORE_HPP
#define CORE_HPP

#include <stdexcept>
#include "Utils.hpp"
#include "Field.hpp"


class Core {
public:
    Core(FieldInteractor &field);
    void userStep(Coordinates coordinates);
    void computerStep();
    bool checkWinPosition();
    bool checkDrawPosition();
private:
    FieldInteractor &_field;
};


#endif // CORE_HPP
