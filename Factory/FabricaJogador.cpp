#include "FabricaJogador.hpp"

Player * FabricaJogador::criarJogador(CharacterType type){

    switch(type){
        case SoldierType:
            return new class Soldier(100,100,SoldierType);
        case ExtractorType:
            return new class Extractor(50,100,ExtractorType);
        default:
            return nullptr;
    }
    return nullptr;
}

