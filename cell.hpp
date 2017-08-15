#pragma once


#include <SFML/System/Vector2.hpp>


struct Cell
{
    sf::Vector2i pos;

    bool operator ==(const Cell& rhs) const {return pos == rhs.pos;}
};