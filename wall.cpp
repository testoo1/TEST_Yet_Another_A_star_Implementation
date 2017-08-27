#include "wall.hpp"

void Wall::insert(iNode& cell)
{
    _data.insert(&cell);
}

void Wall::erase(iNode& cell)
{
    _data.erase(&cell);
}

bool Wall::inWall(iNode& cell)
{
    return(_data.find(&cell) != _data.end());
}

std::unordered_set<iNode*>& Wall::getWall()
{
    return(_data);
}