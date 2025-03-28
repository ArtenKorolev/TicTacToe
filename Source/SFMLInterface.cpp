#include "SFMLInterface.hpp"


SFMLInterface::SFMLInterface(FieldInteractor &field)
    : IOInterface(field), _bot(Bot()), _core(Core(_field, _bot))
{}

void SFMLInterface::gameLoop() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TicTacToe");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        _core.computerStep();
        _drawField(window);
        window.display();
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
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
    cell.setFillColor(sf::Color::White);
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color::Black);

    if (_field.getCellByCoordinates({x, y}).state == CellState::CROSS) {
        sf::Text cross;
        cross.setFont(_font); // Убедитесь, что шрифт загружен
        cross.setString("X");
        cross.setCharacterSize(CELL_SIZE / 2);
        cross.setFillColor(sf::Color::Red);
        cross.setPosition(x * CELL_SIZE + CELL_SIZE / 4, y * CELL_SIZE + CELL_SIZE / 4);
        window.draw(cross);
    } else if (_field.getCellByCoordinates({x, y}).state == CellState::ZERO) {
        sf::Text zero;
        zero.setFont(_font); // Убедитесь, что шрифт загружен
        zero.setString("O");
        zero.setCharacterSize(CELL_SIZE / 2);
        zero.setFillColor(sf::Color::Blue);
        zero.setPosition(x * CELL_SIZE + CELL_SIZE / 4, y * CELL_SIZE + CELL_SIZE / 4);
        window.draw(zero);
    }

    window.draw(cell);
}
