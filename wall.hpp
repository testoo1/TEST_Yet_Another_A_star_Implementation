#pragma once


#include "cell_hash.hpp"

#include <unordered_set>


class Wall
{
private:
    std::unordered_set<Cell,Cell_Hash> _data;

public:
    Wall(){};
    void insert(Cell&);
    void erace(Cell&);
};