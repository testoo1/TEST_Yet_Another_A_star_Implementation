#pragma once


#include "node.hpp"

#include <array>
#include <vector>
#include <unordered_map>

class Graph;


class Neighbors
{
private:
    Graph* _graph {nullptr};

    std::unordered_map<iNode*,std::vector<iNode*>> _data;

    // std::array<std::pair<int,int>, 4> _direction {{{0,-1},{0,1},{1,0},{-1,0}}};
    std::array<std::pair<int,int>, 8> _direction {{{0,-1},{1,0},{0,1},{-1,0},
                                                   {1,-1},{1,1},{-1,1},{-1,-1}}};


public:
    void init(Graph*);
    bool inNeighbors(iNode*);
    std::vector<iNode*> get(iNode&);
};