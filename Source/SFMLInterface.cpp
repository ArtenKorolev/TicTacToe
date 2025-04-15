#include "SFMLInterface.hpp"


SFMLInterface::SFMLInterface(FieldInteractor &field)
    : IOInterface(field), _core(Core(_field, BotFactory::getBot()))
{}

void SFMLInterface::gameLoop() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Tic Tac Toe Game!");
    SFMLDrawer drawer(window);
    window.setFramerateLimit(60); 

    sf::Event event;

    while(window.isOpen()) {
        drawer.drawField(_field); 
        window.display();

        while(window.pollEvent(event)) {
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
            bool playerMadeStep = false;

            if (event.mouseButton.button == sf::Mouse::Left && !_hasWinner) {
                playerMadeStep = _handleUserStep(event);
            }
            if (!_hasWinner && playerMadeStep) {
                _handleComputerStep();
            }
            break;
    }
}

bool SFMLInterface::_handleUserStep(sf::Event &event) {
    bool userMadeStepSuccessfully = _tryToMakeUserStep(event);

    if (!userMadeStepSuccessfully) {
        return false;
    }
    
    _checkForWinOrDraw("Игрок");
    return true;
}

bool SFMLInterface::_tryToMakeUserStep(sf::Event &event) {
    try {
        _core.userStep(_getCoordinatesFromEvent(event)); 
        return true; 
    }
    catch(const std::exception &e) {
        ERROR_FILE_LOGGER.log(e.what());
        return false; 
    }
}

void SFMLInterface::_handleComputerStep() {
    _core.computerStep();
    _checkForWinOrDraw("Компьютер");
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
