#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "GameState.hpp"
#include <vector>
#include <string>

class MainMenuSate : public GameState{
public:
    MainMenuSate();
    ~MainMenuSate() override = default;

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
