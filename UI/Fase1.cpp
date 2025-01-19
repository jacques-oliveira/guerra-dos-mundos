
#include "Fase1.hpp"
#include <stdexcept>

Fase1::Fase1(const std::string& levelName)
: levelCompleted(false), exitGame(false) {
    if (!font.loadFromFile("Assets/Fonts/Good-Game.ttf")) {
        throw std::runtime_error("Erro ao carregar fonte");
    }

    levelText.setFont(font);
    levelText.setString("Playing " + levelName);
    levelText.setCharacterSize(30);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10, 10);
}

void Fase1::processEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            exitGame = true;
            window.close();
        }
    }
    player.handleInput();
}

void Fase1::update() {
    //player.update();
    // Lógica de fase aqui
}

void Fase1::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(levelText);
    player.render(window);
    window.display();
}

bool Fase1::shouldContinue() const {
    return levelCompleted;
}

bool Fase1::shouldExit() const {
    return exitGame;
}
