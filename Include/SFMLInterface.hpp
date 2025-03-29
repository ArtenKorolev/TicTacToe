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
    void _handleEvent(sf::Event &event, sf::Window &window);
    void _handleUserStep(sf::Event &event);
    void _handleComputerStep();
    bool _tryToMakeUserStep(sf::Event &event);
    Coordinates _getCoordinatesFromEvent(sf::Event &event);
    bool _checkForWinOrDraw(const std::string &player);
    void _drawField(sf::RenderWindow &window);
    void _drawCell(sf::RenderWindow &window, int x, int y);
    void _drawEmptyCell(sf::RenderWindow &window, int x, int y);
    void _drawCross(sf::RenderWindow &window, int x, int y);
    void _drawZero(sf::RenderWindow &window, int x, int y);
    Core _core;
    bool _hasWinner = false;
    Bot _bot;
};


#endif // SFMLINTERFACE_HPP
