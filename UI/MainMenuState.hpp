#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "GameState.hpp"
#include <vector>
#include <string>

class MainMenuSate : public GameState{
public:
    MainMenuSate();
    ~MainMenuSate() override = default;
    void processEvents(sf::RenderWindow & window) override;
    void update() override;
    void render(sf::RenderWindow & window) override;
    bool shouldContinue() const override;
    bool shouldExit() const override;

private:
    sf::Font font;
    sf::Text title;
    std::vector<sf::Text> options;
    int selectedOption;
    bool continueGame;
    bool exitGame;

    void updateOptionColors();
};
#endif
