#include <iostream>
#include "Game.hpp"
#include "InputOutputSystem.hpp"


class IO_Mock : public InputOutputSystem {
public:
    IO_Mock(std::unique_ptr<Core> core) 
        : InputOutputSystem(std::move(core))
    {}

    void gameLoop() override {
        // pass
    }
};


int main(int, char**) {
    auto core = std::make_unique<Core>();
    std::unique_ptr<InputOutputSystem> ioSystem = std::make_unique<IO_Mock>(std::move(core));

    Game game(std::move(ioSystem));
    int exitCode = game.run();
    return exitCode;
}
