#pragma once

#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game{

public :
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void renderer();
    void clean();

    bool running(){ return isRunning;};

private:
    bool isRunning;
    sf::Window *window;
    sf::RenderWindow *renderWindow;
};
