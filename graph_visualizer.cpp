#include "graph_visualizer.hpp"

Graph_visualizer::Graph_visualizer(Graph& graph, sf::RenderWindow& target):
    _graph(graph),
    _target(target)
{}

void Graph_visualizer::init()
{
    // REAL value for final application (uncomment this)
    // for window(800,800) gap = 4
    // _gap = _target.getSize().x/((_graph._size-1)*10*2);
    
    // TEMP value for test cell detection algoritm (isPointToCell)
    _gap = 20;
    _cellSize = static_cast<float>(_target.getSize().x - _gap*(_graph._size-1))/_graph._size;
    _cell.setSize(sf::Vector2f(_cellSize,_cellSize));

    _baseTexture.create(_target.getSize().x, _target.getSize().y);
    drawBase(_baseTexture);
}

void Graph_visualizer::render()
{
    // Draw field
    _target.draw(sf::Sprite(_base.getTexture()));

    // Draw wall
    for(auto element: _graph._wall.getWall())
    {
        draw(&element, CellType::Wall);
    }

    // Draw start and stop cells
    draw(_graph._start, CellType::Start);
    draw(_graph._stop, CellType::Stop);
}

void Graph_visualizer::draw(Cell* cell, CellType type)
{
    draw(_target, cell, type);
}

void Graph_visualizer::draw(sf::RenderTarget& target, Cell* cell, CellType type)
{
    sf::Color color;
    switch(type)
    {
        case(CellType::Empty):
            color = sf::Color::White;
            break;
        case(CellType::Wall):
            color = sf::Color::Black;
            break;
        case(CellType::Start):
            color = sf::Color::Green;
            break;
        case(CellType::Stop):
            color = sf::Color::Red;
            break;
        case(CellType::Frontier):
            color = sf::Color::Blue;
            break;
        case(CellType::Visited):
            color = sf::Color::Cyan;
            break;
    }
    _cell.setFillColor(color);

    float x = (_cellSize + _gap)*cell->pos.x;
    float y = (_cellSize + _gap)*cell->pos.y;

    _cell.setPosition(x,y);
    target.draw(_cell);

    _cell.setFillColor(sf::Color::White);
}

void Graph_visualizer::drawBase(sf::RenderTarget& target)
{
    for(auto row: _graph._data)
    {
        for(auto cell: row)
        {
            draw(_baseTexture, &cell);
        }
    }    
}

bool Graph_visualizer::isPointToCell(sf::Vector2i& coord)
{
    return(coord.x%(static_cast<int>(_cellSize) + _gap) < static_cast<int>(_cellSize) &&
           coord.y%(static_cast<int>(_cellSize) + _gap) < static_cast<int>(_cellSize));   
}

sf::Vector2i Graph_visualizer::getCellCoord(sf::Vector2i coord)
{
    if(isPointToCell(coord))
    {
        int x = (coord.x*_graph._size)/_target.getSize().x;
        int y = (coord.y*_graph._size)/_target.getSize().y;

        if(x >= 0 && x < _graph._size &&
           y >= 0 && y < _graph._size)
        {
            return(sf::Vector2i(x,y));            
        }
    }

    return(sf::Vector2i(-1,-1));
}