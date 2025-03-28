#ifndef IOINTERFACEFACTORY_HPP
#define IOINTERFACEFACTORY_HPP

#include <memory>
#include "IOInterface.hpp"


class IOInterfaceFactory {
public:
    static std::unique_ptr<IOInterface> getIOInterface(FieldInteractor &field);
};


#endif // IOINTERFACEFACTORY_HPP
