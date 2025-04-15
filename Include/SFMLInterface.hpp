#ifndef SFMLINTERFACE_HPP
#define SFMLINTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "chrono"
#include "Constants.hpp"
#include "GlobalObjects.hpp"
#include "IOInterface.hpp"
#include "BotFactory.hpp"
#include "SFMLDrawer.hpp"
#include "Bot.hpp"


class SFMLInterface : public IOInterface{
public:
    SFMLInterface(FieldInteractor &field);
    ~SFMLInterface() override = default;
    void gameLoop() override;
private:
    void _handleEvent(sf::Event &event, sf::Window &window);
    bool _handleUserStep(sf::Event &event);
    void _handleComputerStep();
    bool _tryToMakeUserStep(sf::Event &event);
    Coordinates _getCoordinatesFromEvent(sf::Event &event);
    bool _checkForWinOrDraw(const std::string &player);
    Core _core;
    bool _hasWinner = false;
};


#endif // SFMLINTERFACE_HPP
