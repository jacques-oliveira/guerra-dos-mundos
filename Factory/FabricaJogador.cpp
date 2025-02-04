#include "FabricaJogador.hpp"

Player * FabricaJogador::criarJogador(float posx, float posy, CharacterType type){

    switch(type){
        case SoldierType:
            return new class Soldado(posx,posy,SoldierType);
        case ColetorType:
            return new class Coletor(posx,posy,ColetorType);
        default:
            return nullptr;
    }
    return nullptr;
}

