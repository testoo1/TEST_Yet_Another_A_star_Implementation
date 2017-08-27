#pragma once


#include "graph.hpp"
#include "graph_visualizer.hpp"
#include "a_star.hpp"
#include "ui.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


class App
{
private:
    sf::RenderWindow _window;

    Graph            _grid;
    Graph_visualizer _visualizer;
    UI               _ui;
    A_star           _a_star;

    enum class Operation
    {
        None,
        Move,
        Draw,
        Erase
    };

   friend UI;

public:
    App();
    void run();
    void processEvent();
    void render();

    bool inWindow(sf::Vector2i&);
};