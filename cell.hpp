#pragma once


#include <SFML/System/Vector2.hpp>


struct Cell
{
    sf::Vector2i pos;

    Cell(){pos.x = -1; pos.y = -1;};
    Cell(int i, int j){pos.x = i; pos.y = j;}

    bool operator ==(const Cell& rhs) const {return pos == rhs.pos;}
    bool operator !=(const Cell& rhs) const {return pos != rhs.pos;}
};