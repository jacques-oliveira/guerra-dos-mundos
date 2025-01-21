#ifndef FASE1_HPP
#define FASE1_HPP

#include "Fase.hpp"
#include "../Player.hpp"
#include "../TileGenerator.hpp"

class Fase1 : public Fase{
public:
    Fase1(const std::string& levelName);
    ~Fase1() override = default;

    void processEvents(sf::RenderWindow & window) override;
    void update() override;
    void render(sf::RenderWindow & window) override;

};
#endif
