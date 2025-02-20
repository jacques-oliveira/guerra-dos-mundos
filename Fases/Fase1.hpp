#ifndef FASE1_HPP
#define FASE1_HPP

#include "Fase.hpp"
#include "../GeradorMapa/TileGenerator.hpp"
#include "../Factory/FabricaJogador.hpp"
#include "../GeradorMapa/FonteEnergia.hpp"

class Fase1 : public Fase{
public:
    Fase1(const std::string& levelName);
    ~Fase1() ;

    void processEvents(sf::RenderWindow & window, bool * isRunning) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow & window) override;

private:
    void initLevel(std::string);
    void criarSoldados();
    void selecaoPersonagens(sf::Event& event, sf::RenderWindow& _window);
    sf::Sprite spriteMapaFase1;
    sf::Texture textureMapaFase1;
    std::vector<FonteEnergia*> fontesEnergia;
    sf::Clock clock;
    float velocidadeView;
    float bordaMargem;
    void moverViewMouse();
};
#endif
