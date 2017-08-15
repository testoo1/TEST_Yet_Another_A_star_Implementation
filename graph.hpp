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

    Cell* _start;
    Cell* _stop;

    friend Neighbors;
    friend Graph_visualizer;

public:
    Wall  _wall;
    Neighbors _neighbors;

    void setStart(Cell&);
    void setStop(Cell&);
};





