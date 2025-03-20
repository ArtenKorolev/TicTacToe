#ifndef CORE_HPP
#define CORE_HPP

#include <stdexcept>
#include "Utils.hpp"
#include "Field.hpp"


class Core {
public:
    Core();
    void userStep(int x, int y);
    void computerStep();
    bool checkWinPosition();
    bool checkDrawPosition();
private:
    FieldInteractor _field;
};


#endif // CORE_HPP
