#include "Game.hpp"

Game::Game(std::unique_ptr<InputOutputSystem> ioSystem) 
    : _io(std::move(ioSystem))
{}

int Game::run() {
    _io->gameLoop();
    return 0;
}
