#pragma once


#include "cell.hpp"

#include <functional>
#include <cstdlib>


struct Cell_Hash
{
    std::size_t operator()(const Cell& cell) const
    {
        std::size_t h1 = std::hash<int>{}(cell.pos.x);
        std::size_t h2 = std::hash<int>{}(cell.pos.y);
        return h1 ^ (h2 << 1);
    }
};