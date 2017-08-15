#pragma once


#include <SFML/Graphics.hpp>

class Graph;
class Cell;


class Graph_visualizer
{
public:
    enum class CoordSystem
    {
        Cartesian,
        Grid
    };

private:
    Graph& _data;

    sf::RectangleShape _cell;
    int _gap;

    sf::Texture _base;

    enum class CellType
    {
        Wall,
        Start,
        Stop,
        Frontier,
        Visited     
    };

public:
    Graph_visualizer(Graph&);

    void drawTo(sf::RenderWindow target);
    void draw(Cell&);

    // CS - Coordinare System
    sf::Vector2f changeCS(sf::Vector2f, CoordSystem);
};