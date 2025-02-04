#ifndef FABRICAJOGADOR_HPP
#define FABRICAJOGADOR_HPP

#include "../Player/Player.hpp"
#include "../Character/Soldado.hpp"
#include "../Character/Coletor.hpp"
#include "../Character/CharacterType.hpp"

class FabricaJogador{
public:
    static Player* criarJogador(float posx, float posy,CharacterType type);
private:
    bool possuiRecurso(CharacterType type) const;
    void gastarRecurso(CharacterType type);
};
#endif
