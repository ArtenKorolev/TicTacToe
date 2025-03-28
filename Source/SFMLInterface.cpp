#include "SFMLInterface.hpp"


SFMLInterface::SFMLInterface(FieldInteractor &field)
    : IOInterface(field), _bot(Bot()), _core(Core(_field, _bot))
{}

void SFMLInterface::gameLoop() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TicTacToe");

    while (window.isOpen()) {
        sf::Event event;
        _handleEvents(window);
        window.clear(sf::Color::Black);
        _drawField(window);
        window.display();
    }

}

// TODO: Refactor this function

void SFMLInterface::_handleEvents(sf::RenderWindow &window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } 
        else if (event.type == sf::Event::MouseButtonPressed && _playerCanMove) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x / CELL_SIZE;
                int y = event.mouseButton.y / CELL_SIZE;
                Coordinates coordinates{x, y};
                try {
                    _core.userStep(coordinates);
                    if (_core.checkWinPosition()) {
                        GAME_FILE_LOGGER.log("Пользователь выиграл!");
                        _playerCanMove = false;
                        return;
                    } else if (_core.checkDrawPosition()) {
                        _playerCanMove = false;
                        GAME_FILE_LOGGER.log("Ничья!");
                        return;
                    }
                    _core.computerStep();
                    if (_core.checkWinPosition()) {
                        _playerCanMove = false;
                        GAME_FILE_LOGGER.log("Компьютер выиграл!");
                    } else if (_core.checkDrawPosition()) {
                        _playerCanMove = false;
                        GAME_FILE_LOGGER.log("Ничья!");
                    }
                } catch (const std::exception &e) {
                    ERROR_FILE_LOGGER.log(e.what());
                }
            }
        }
    }
}

void SFMLInterface::_drawField(sf::RenderWindow &window) {
    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            _drawCell(window, i, j);
        }
    }
}

void SFMLInterface::_drawCell(sf::RenderWindow &window, int x, int y) {
    // Рисуем клетку
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
    cell.setFillColor(sf::Color::White);
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color::Black);
    window.draw(cell);

    // Получаем состояние клетки
    CellState cellState = _field.getCellByCoordinates({x, y}).state;

    if (cellState == CellState::CROSS) {
        // Рисуем крестик как два пересекающихся прямоугольника
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
    } else if (cellState == CellState::ZERO) {
        // Рисуем нолик как круг с дыркой
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
}
