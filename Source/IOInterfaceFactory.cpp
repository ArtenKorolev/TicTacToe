#include "IOInterfaceFactory.hpp"


std::unique_ptr<IOInterface> IOInterfaceFactory::getIOInterface(FieldInteractor &field) {
    return std::make_unique<ConsoleInterface>(field);
}
