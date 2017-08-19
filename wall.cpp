#include "wall.hpp"

void Wall::insert(Cell& cell)
{
    _data.insert(cell);
}

void Wall::erase(Cell& cell)
{
    _data.erase(cell);
}

bool Wall::inWall(Cell& cell)
{
    return(_data.find(cell) != _data.end());
}

std::unordered_set<Cell,Cell_Hash>& Wall::getWall()
{
    return(_data);
}