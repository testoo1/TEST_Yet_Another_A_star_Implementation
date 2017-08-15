#pragma once


#include "graph.hpp"
#include "graph_visualizer.hpp"
#include "ui.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


class App
{
private:
    sf::RenderWindow _window;

    Graph            _grid;
    Graph_visualizer _visualizer;
    UI               _ui;
    // A_star           _a_star;

    friend UI;

public:
    App();
    void run();
    void processEvent();
    void render();


};