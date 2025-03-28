#ifndef SFMLINTERFACE_HPP
#define SFMLINTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "chrono"
#include "Constants.hpp"
#include "Globals.hpp"
#include "IOInterface.hpp"
#include "Bot.hpp"


class SFMLInterface : public IOInterface{
public:
    SFMLInterface(FieldInteractor &field);
    ~SFMLInterface() override = default;
    void gameLoop() override;
private:
    void _handleEvents(sf::RenderWindow &window);
    void _drawField(sf::RenderWindow &window);
    void _drawCell(sf::RenderWindow &window, int x, int y);
    Core _core;
    bool _playerCanMove = true;
    Bot _bot;
};


class SFMLUtils {
public:
};


#endif // SFMLINTERFACE_HPP
