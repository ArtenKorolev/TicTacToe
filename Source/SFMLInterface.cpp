#include "SFMLInterface.hpp"

SFMLInterface::SFMLInterface(FieldInteractor &field)
    : IOInterface(field), _core(Core(_field, BotFactory::getBot())) {}

void SFMLInterface::gameLoop() {
  sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_WIDTH}),
                          "Tic Tac Toe Game!");

  SFMLDrawer drawer(window);

  while (window.isOpen()) {
    window.clear(sf::Color::White);

    drawer.drawField(_field);
    window.display();

    while (auto event = window.pollEvent()) {
      _handleEvent(*event, window);
    }
  }
}

void SFMLInterface::_handleEvent(sf::Event &event, sf::RenderWindow &window) {
  if (event.is<sf::Event::Closed>()) {
    window.close();
    return;
  }

  if (event.is<sf::Event::MouseButtonPressed>()) {
    _handleMouseButtonPressed(event);
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
  } catch (const std::exception &e) {
    ERROR_FILE_LOGGER.log(e.what());
    return false;
  }
}

Coordinates SFMLInterface::_getCoordinatesFromEvent(sf::Event &event) {
  if (const auto *mouse = event.getIf<sf::Event::MouseButtonPressed>()) {

    int x = mouse->position.x / CELL_SIZE;
    int y = mouse->position.y / CELL_SIZE;
    return {x, y};
  }

  return {-1, -1}; // защитный случай
}

bool SFMLInterface::_checkForWinOrDraw(const std::string &player) {
  if (_core.checkWinPosition()) {
    _hasWinner = true;
    GAME_FILE_LOGGER.log(player + " выиграл!");
    return true;
  } else if (_core.checkDrawPosition()) {
    _hasWinner = true;
    return true;
  }

  return false;
}
