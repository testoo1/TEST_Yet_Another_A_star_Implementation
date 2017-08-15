#pragma once


#include <imgui.h>
#include <imgui-sfml.h>

#include <SFML/System/Clock.hpp>

class App;


class UI
{
private:
    App& _app;

public:
     UI(App&);
     
     void update();
     void draw();
     
}; 