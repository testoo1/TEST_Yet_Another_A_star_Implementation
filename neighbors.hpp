#pragma once


#include "cell_hash.hpp"

#include <vector>
#include <unordered_map>


class Neighbors
{
private:
    std::unordered_map<Cell,std::vector<Cell*>,Cell_Hash> _data;

public:
    Neighbors(){};
    void insert(Cell&);
    void find(Cell&);
    void get(Cell&);
};