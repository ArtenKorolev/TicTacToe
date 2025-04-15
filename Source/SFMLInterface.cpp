#include "SFMLInterface.hpp"


SFMLInterface::SFMLInterface(FieldInteractor &field)
    : IOInterface(field), _core(Core(_field, BotFactory::getBot()))
{}

void SFMLInterface::gameLoop() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Tic Tac Toe Game!");
    SFMLDrawer drawer(window);

    sf::Event event;

    while (window.isOpen()) {
        drawer.drawField(_field); 
        window.display();

        while (window.pollEvent(event)) {
            _handleEvent(event, window);
        }

        window.clear(sf::Color::White); 
    }
}

void SFMLInterface::_handleEvent(sf::Event &event, sf::Window &window) {
    switch(event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            _handleMouseButtonPressed(event);
            break;
    }
}

void SFMLInterface::_handleMouseButtonPressed(sf::Event &event) {
    if (_hasWinner) {
        return;
    }

    bool playerStepedSuccessfully = _tryToMakeUserStep(event);

    if (!playerStepedSuccessfully) {
        return;
    }

    if (_checkForWinOrDraw("Игрок")) {
        return;
    }

    _core.computerStep();

    _checkForWinOrDraw("Компьтер");
}

bool SFMLInterface::_tryToMakeUserStep(sf::Event &event) {
    try {
        _core.userStep(_getCoordinatesFromEvent(event)); 
        return true; 
    }
    catch (const std::exception &e) {
        ERROR_FILE_LOGGER.log(e.what());
        return false; 
    }
}

Coordinates SFMLInterface::_getCoordinatesFromEvent(sf::Event &event) {
    int x = event.mouseButton.x / CELL_SIZE;
    int y = event.mouseButton.y / CELL_SIZE;
    return {x, y}; 
}

bool SFMLInterface::_checkForWinOrDraw(const std::string &player) {
    if (_core.checkWinPosition()) {
        _hasWinner = true;
        GAME_FILE_LOGGER.log(player + " выиграл!");
        return true; 
    } 
    else if (_core.checkDrawPosition()) {
        _hasWinner = true;
        return true;
    }

    return false;
}
