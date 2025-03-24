#ifndef IOINTERFACE_HPP
#define IOINTERFACE_HPP

#include "Core.hpp"
#include "memory"


class IOInterface {
public:
    IOInterface(FieldInteractor &field);
    virtual ~IOInterface() = default;
    virtual void gameLoop() = 0;
protected:
    FieldInteractor &_field;
};


#endif // IOINTERFACE_HPP
