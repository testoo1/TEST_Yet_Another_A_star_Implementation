#pragma once


#include "node.hpp"

#include <unordered_set>


class Wall
{
private:
    std::unordered_set<iNode*> _data;

public:
    void insert(iNode&);
    void erase(iNode&);

    bool inWall(iNode&);
    std::unordered_set<iNode*>& getWall();
};