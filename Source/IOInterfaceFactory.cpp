#include "IOInterfaceFactory.hpp"


class IO_Mock : public IOInterface {    
public:
    IO_Mock(FieldInteractor &field) : IOInterface(field) {}

    void gameLoop() {
        // pass
    }
};


std::unique_ptr<IOInterface> IOInterfaceFactory::getIOInterface(FieldInteractor &field) {
    return std::make_unique<IO_Mock>(field);
}
