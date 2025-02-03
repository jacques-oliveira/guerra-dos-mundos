#ifndef FABRICAJOGADOR_HPP
#define FABRICAJOGADOR_HPP

#include "../Player/Player.hpp"

class FabricaJogador{
public:
    static Player* criarJogador(CharacterType type);
private:
    bool possuiRecurso(CharacterType type) const;
    void gastarRecurso(CharacterType type);
};
#endif
