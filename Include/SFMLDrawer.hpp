#ifndef _SFMLDRAWER_HPP_
#define _SFMLDRAWER_HPP_

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "Field.hpp"


class SFMLDrawer {
public:
    SFMLDrawer(sf::RenderWindow &window);
    void drawField(FieldInteractor &field);
private:
    void _drawCell(Coordinates coords, FieldInteractor &field);
    void _drawEmptyCell(Coordinates coords);
    void _drawCross(Coordinates coords);
    void _drawZero(Coordinates coords);
    sf::RenderWindow &_window;
};


#endif // _SFMLDRAWER_HPP_
