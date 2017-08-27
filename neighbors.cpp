#include "neighbors.hpp"
#include "graph.hpp"

void Neighbors::init(Graph* graph)
{
    _graph = graph;
}

bool Neighbors::inNeighbors(iNode* cell)
{
    return(_data.find(cell) != _data.end());
}

std::vector<iNode*> Neighbors::get(iNode& cell)
{
    if(inNeighbors(&cell))
    {
        return(_data[&cell]);
    }
    else
    {   
        std::vector<iNode*> neighbors;

        for(auto& direction: _direction)
        {
            sf::Vector2i pos {cell.x + direction.first,
                              cell.y + direction.second};

            if(_graph->inGraph(pos))
            {
                neighbors.push_back(&_graph->getNode(pos));
            }
        }
        _data[&cell] = neighbors;

        return(neighbors);
    }
}