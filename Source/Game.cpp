#include "Game.hpp"


int Game::run() {
    try {
        Field field;
        FieldInteractor fieldInteractor(field);
        auto interface = IOInterfaceFactory::getIOInterface(fieldInteractor);   
        interface->gameLoop();
    }
    catch (const std::exception &e) {
        FileLogger errorsLogger(File{"errors.txt", "./"});
        errorsLogger.log(e.what());
        return 1;
    }

    return 0;
}
