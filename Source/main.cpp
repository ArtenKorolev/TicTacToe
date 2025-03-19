#include <iostream>
#include "Game.hpp"
#include "InputOutputSystem.hpp"


int main(int, char**) {
    auto core = std::make_unique<Core>();
    auto ioSystem = std::make_unique<InputOutputSystem>(std::move(core));

    Game game(std::move(ioSystem));
    int exitCode = game.run();
    return exitCode;
}
