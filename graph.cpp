#include "graph.hpp"

Graph::Graph(int size): _size(size)
{
    for(int i=0; i<_size; ++i)
    {
        std::vector<Cell> row;

        for(int j=0; j<_size; ++j)
        {
            row.push_back(Cell(i,j));
        }

        _data.push_back(row);
    }

    _start = &_data[1][1];
    _stop  = &_data[_size-2][_size-2];
}

Cell& Graph::getCell(sf::Vector2i& coord)
{
    return(_data[coord.x][coord.y]);
}

bool Graph::canBeMoved(Cell& cell)
{
    return(cell == *_start || cell == *_stop);
}

bool Graph::canBePlaced(Cell& cell)
{
    return(cell != *_start && cell != *_stop && !_wall.inWall(cell));
}

bool Graph::canBeWalled(Cell& cell)
{
    return(!canBeMoved(cell));
}

bool Graph::inGraph(sf::Vector2i coord)
{
    return(coord.x != -1 && coord.y != -1);
}