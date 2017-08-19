#pragma once


#include "cell_hash.hpp"

#include <unordered_set>


class Wall
{
private:
    std::unordered_set<Cell,Cell_Hash> _data;

public:
    void insert(Cell&);
    void erase(Cell&);

    bool inWall(Cell&);
    std::unordered_set<Cell,Cell_Hash>& getWall();
};