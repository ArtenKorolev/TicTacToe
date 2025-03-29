#include "SFMLInterface.hpp"


SFMLInterface::SFMLInterface(FieldInteractor &field)
    : IOInterface(field), _bot(Bot()), _core(Core(_field, _bot))
{}

void SFMLInterface::gameLoop() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Tic Tac Toe Game!");
    window.setFramerateLimit(60); 

    sf::Event event;

    while(window.isOpen()) {
        _drawField(window); 
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
            if (event.mouseButton.button == sf::Mouse::Left && !_hasWinner) {
                _handleUserStep(event);
            }
            if (!_hasWinner) {
                _handleComputerStep();
            }
            break;
    }
}

void SFMLInterface::_handleUserStep(sf::Event &event) {
    if (!_tryToMakeUserStep(event)) return;
    _checkForWinOrDraw("Игрок");
}

void SFMLInterface::_handleComputerStep() {
    _core.computerStep();
    _checkForWinOrDraw("Компьютер");
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

void SFMLInterface::_drawField(sf::RenderWindow &window) {
    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            _drawCell(window, i, j);
        }
    }
}

void SFMLInterface::_drawCell(sf::RenderWindow &window, int x, int y) {
    _drawEmptyCell(window, x, y);
    CellState cellState = _field.getCellByCoordinates({x, y}).state;

    if (cellState == CellState::CROSS) {
        _drawCross(window, x, y); 
    } 
    else if (cellState == CellState::ZERO) {
        _drawZero(window, x, y); 
    }
}

void SFMLInterface::_drawEmptyCell(sf::RenderWindow &window, int x, int y) {
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
    cell.setFillColor(sf::Color::White);
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color::Black);
    window.draw(cell);
}

void SFMLInterface::_drawCross(sf::RenderWindow &window, int x, int y) {
    sf::RectangleShape line1(sf::Vector2f(CELL_SIZE * 0.7f, CELL_SIZE * 0.1f));
    line1.setFillColor(sf::Color::Red);
    line1.setOrigin(line1.getSize().x / 2, line1.getSize().y / 2);
    line1.setPosition(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
    line1.setRotation(45); // Поворот первой линии

    sf::RectangleShape line2(sf::Vector2f(CELL_SIZE * 0.7f, CELL_SIZE * 0.1f));
    line2.setFillColor(sf::Color::Red);
    line2.setOrigin(line2.getSize().x / 2, line2.getSize().y / 2);
    line2.setPosition(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
    line2.setRotation(-45); // Поворот второй линии

    window.draw(line1);
    window.draw(line2);
}

void SFMLInterface::_drawZero(sf::RenderWindow &window, int x, int y) {
    sf::CircleShape outerCircle(CELL_SIZE / 2.5f);
    outerCircle.setFillColor(sf::Color::White);
    outerCircle.setOutlineThickness(5);
    outerCircle.setOutlineColor(sf::Color::Blue);
    outerCircle.setOrigin(outerCircle.getRadius(), outerCircle.getRadius());
    outerCircle.setPosition(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);

    sf::CircleShape innerCircle(CELL_SIZE / 4.0f);
    innerCircle.setFillColor(sf::Color::White);
    innerCircle.setOrigin(innerCircle.getRadius(), innerCircle.getRadius());
    innerCircle.setPosition(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);

    window.draw(outerCircle);
    window.draw(innerCircle);
}
