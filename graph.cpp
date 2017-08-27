#include "graph.hpp"

Graph::Graph(int size): _size(size)
{
    // init Graph
    for(int i=0; i<_size; ++i)
    {
        std::vector<iNode> row;

        for(int j=0; j<_size; ++j)
        {
            row.push_back(iNode(i,j));
        }

        _data.push_back(row);
    }

    _start = &_data[1][1];
    _stop  = &_data[_size-2][_size-2];

    // init Neighbors
    _neighbors.init(this);
}

iNode& Graph::getNode(sf::Vector2i coord)
{
    return(_data[coord.x][coord.y]);
}

// TEMP ->
double Graph::cost(iNode* left, iNode* right)
{
    if( (left->x - right->x) != 0 && (left->y - right->y))
    {
        return(1.4142); //sqrt(2)        
    }
    else
    {
        return(1);
    }

}
// TEMP <-

bool Graph::canBeMoved(iNode& cell)
{
    return(cell == *_start || cell == *_stop);
}

bool Graph::canBePlaced(iNode& cell)
{
    return(cell != *_start && cell != *_stop && !_wall.inWall(cell));
}

bool Graph::canBeWalled(iNode& cell)
{
    return(!canBeMoved(cell));
}

bool Graph::inGraph(sf::Vector2i coord)
{
    return(coord.x >= 0 && coord.x < _size &&
           coord.y >= 0 && coord.y < _size);
}