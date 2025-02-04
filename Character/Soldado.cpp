#include "Soldado.hpp"

Soldado::Soldado(float posx, float posy, CharacterType type) : Player(posx, posy, type){

}

Soldado::~Soldado(){
}

void Soldado::gritoAtaque(){
    std::cout<<"Soldado Combate!"<<std::endl;
}




