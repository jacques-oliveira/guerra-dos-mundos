#include "Coletor.hpp"

Coletor::Coletor(float posx, float posy, TipoPersonagem tipo): Player(posx, posy, tipo){
}

void Coletor::coletarRecurso(){
    std::cout<<"Coleta iniciada!"<<std::endl;
}



