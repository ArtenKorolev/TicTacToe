#ifndef SFMLINTERFACE_HPP
#define SFMLINTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Constants.hpp"
#include "IOInterface.hpp"
#include "Bot.hpp"


class SFMLInterface : public IOInterface{
public:
    SFMLInterface(FieldInteractor &field);
    ~SFMLInterface() override = default;
    void gameLoop() override;
private:
    void _drawField(sf::RenderWindow &window);
    void _drawCell(sf::RenderWindow &window, int x, int y);
    Core _core;
    Bot _bot;
    sf::Font _font = sf::Font();
};


class SFMLUtils {
public:
};


#endif // SFMLINTERFACE_HPP
