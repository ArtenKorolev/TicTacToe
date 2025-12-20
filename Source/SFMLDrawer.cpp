#include "SFMLDrawer.hpp"

SFMLDrawer::SFMLDrawer(sf::RenderWindow &window) : _window(window) {}

void SFMLDrawer::drawField(FieldInteractor &field) {
  for (int i = 0; i < FIELD_HEIGHT; ++i) {
    for (int j = 0; j < FIELD_WIDTH; ++j) {
      _drawCell({i, j}, field);
    }
  }
}

void SFMLDrawer::_drawCell(Coordinates coords, FieldInteractor &field) {
  _drawEmptyCell(coords);
  CellState cellState = field.getCellByCoordinates(coords).state;

  if (cellState == CellState::CROSS) {
    _drawCross(coords);
  } else if (cellState == CellState::ZERO) {
    _drawZero(coords);
  }
}

void SFMLDrawer::_drawEmptyCell(Coordinates coords) {
  int x = coords.x, y = coords.y;

  sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
  cell.setPosition(
      {static_cast<float>(x) * CELL_SIZE, static_cast<float>(y) * CELL_SIZE});
  cell.setFillColor(sf::Color::White);
  cell.setOutlineThickness(1);
  cell.setOutlineColor(sf::Color::Black);
  _window.draw(cell);
}

void SFMLDrawer::_drawCross(Coordinates coords) {
  int x = coords.x, y = coords.y;

  sf::RectangleShape line1(sf::Vector2f(CELL_SIZE * 0.7f, CELL_SIZE * 0.1f));
  line1.setFillColor(sf::Color::Red);
  line1.setOrigin({line1.getSize().x / 2, line1.getSize().y / 2});
  line1.setPosition({static_cast<float>(x * CELL_SIZE + CELL_SIZE / 2),
                     static_cast<float>(y * CELL_SIZE + CELL_SIZE / 2)});
  line1.setRotation(sf::degrees(45.f)); // Поворот первой линии

  sf::RectangleShape line2(sf::Vector2f(CELL_SIZE * 0.7f, CELL_SIZE * 0.1f));
  line2.setFillColor(sf::Color::Red);
  line2.setOrigin({line2.getSize().x / 2, line2.getSize().y / 2});
  line2.setPosition({static_cast<float>(x * CELL_SIZE + CELL_SIZE / 2),
                     static_cast<float>(y * CELL_SIZE + CELL_SIZE / 2)});
  line2.setRotation(sf::degrees(-45.f)); // Поворот второй линии

  _window.draw(line1);
  _window.draw(line2);
}

void SFMLDrawer::_drawZero(Coordinates coords) {
  int x = coords.x, y = coords.y;

  sf::CircleShape outerCircle(CELL_SIZE / 2.5f);
  outerCircle.setFillColor(sf::Color::White);
  outerCircle.setOutlineThickness(5);
  outerCircle.setOutlineColor(sf::Color::Blue);
  outerCircle.setOrigin({outerCircle.getRadius(), outerCircle.getRadius()});
  outerCircle.setPosition({static_cast<float>(x * CELL_SIZE + CELL_SIZE / 2),
                           static_cast<float>(y * CELL_SIZE + CELL_SIZE / 2)});

  sf::CircleShape innerCircle(CELL_SIZE / 4.0f);
  innerCircle.setFillColor(sf::Color::White);
  innerCircle.setOrigin({innerCircle.getRadius(), innerCircle.getRadius()});
  innerCircle.setPosition({static_cast<float>(x * CELL_SIZE + CELL_SIZE / 2),
                           static_cast<float>(y * CELL_SIZE + CELL_SIZE / 2)});

  _window.draw(outerCircle);
  _window.draw(innerCircle);
}
