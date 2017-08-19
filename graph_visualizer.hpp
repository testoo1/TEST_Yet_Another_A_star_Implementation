#pragma once


#include "graph.hpp"
#include "cell.hpp"

#include <SFML/Graphics.hpp>

#include <cmath>


class Graph_visualizer
{
public:
    enum class CoordSystem
    {
        Cartesian,
        Grid
    };

private:
    Graph& _graph;
    sf::RenderWindow& _target;

    sf::RectangleShape _cell;

    float _cellSize;
    int _gap;

    sf::RenderTexture _baseTexture;

    enum class CellType
    {
        Empty,
        Wall,
        Start,
        Stop,
        Frontier,
        Visited     
    };

public:
    Graph_visualizer(Graph&, sf::RenderWindow&);

    void init();

    void render();

    void draw(Cell*, CellType=CellType::Empty);
    void draw(sf::RenderTarget&, Cell*, CellType=CellType::Empty);

    void drawBase(sf::RenderTarget&);

    sf::Vector2i getCellCoord(sf::Vector2i);

    bool isPointToCell(sf::Vector2i&);
};