#ifndef GAME_HPP
#define GAME_HPP

#include "InputOutputSystem.hpp"
#include <memory>


class Game {
public:
    Game(std::unique_ptr<InputOutputSystem> ioSystem);
    int run();
private:
    const std::unique_ptr<InputOutputSystem> _io;
};


#endif // GAME_HPP
