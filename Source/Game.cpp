#include "Game.hpp"


Game::Game(std::unique_ptr<InputOutputSystem> ioSystem) 
    : _io(std::move(ioSystem))
{}

int Game::run() {
    try {
        _io->gameLoop();
    }
    catch (const std::exception &e) {
        return 1;
    }
    
    return 0;
}
