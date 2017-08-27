#pragma once


#include "node.hpp"
#include "neighbors.hpp"
#include "wall.hpp"

#include <SFML/System/Vector2.hpp>

#include <vector>

class Graph_visualizer;


class Graph
{
private:
    int _size;
    std::vector<std::vector<iNode>> _data;    

    friend Neighbors;
    friend Graph_visualizer;

public:
    iNode* _start;
    iNode* _stop;

    Wall  _wall;
    Neighbors _neighbors;

    Graph(int size);

    iNode& getNode(sf::Vector2i);

    double cost(iNode*, iNode*);

    bool canBeMoved(iNode&);
    bool canBePlaced(iNode&);

    bool canBeWalled(iNode&);

    bool inGraph(sf::Vector2i);
};





