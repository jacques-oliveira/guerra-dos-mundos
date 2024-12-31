#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.cpp"

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024,768),"Guerra dos Mundos");
    Player * player = new Player();

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.display();
    }
    return 0;
}
