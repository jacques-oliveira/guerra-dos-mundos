
#include "Fase.hpp"
#include <stdexcept>

Fase::Fase(const std::string& levelName)
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

void Fase::processEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            exitGame = true;
            window.close();
        }
    }
    player.handleInput();
}

void Fase::update() {
    //player.update();
    // Lógica de fase aqui
}

void Fase::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(levelText);
    player.render(window);
    window.display();
}

bool Fase::shouldContinue() const {
    return levelCompleted;
}

bool Fase::shouldExit() const {
    return exitGame;
}
