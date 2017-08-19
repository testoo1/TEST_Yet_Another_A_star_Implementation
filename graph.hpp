#pragma once


#include "cell.hpp"
#include "neighbors.hpp"
#include "wall.hpp"

#include <vector>

class Graph_visualizer;


class Graph
{
private:
    int _size;
    std::vector<std::vector<Cell>> _data;    

    friend Neighbors;
    friend Graph_visualizer;

public:
    Cell* _start;
    Cell* _stop;

    Wall  _wall;
    Neighbors _neighbors;

    Graph(int size);

    Cell& getCell(sf::Vector2i& coord);

    bool canBeMoved(Cell&);
    bool canBePlaced(Cell&);

    bool canBeWalled(Cell&);

    bool inGraph(sf::Vector2i);
};





