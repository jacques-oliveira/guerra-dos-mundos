
#include "PlayState.hpp"
#include <stdexcept>

PlayState::PlayState(const std::string& levelName)
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

void PlayState::processEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            exitGame = true;
            window.close();
        }
    }
    player.handleInput();
}

void PlayState::update() {
    //player.update();
    // Lógica de fase aqui
}

void PlayState::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(levelText);
    player.render(window);
    window.display();
}

bool PlayState::shouldContinue() const {
    return levelCompleted;
}

bool PlayState::shouldExit() const {
    return exitGame;
}
