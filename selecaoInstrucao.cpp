#include "selecaoInstrucao.hpp"

SelecaoInstrucao::SelecaoInstrucao(RI *representacao_intermediaria)
{
    this->representcao_intermediaria = representcao_intermediaria;
    contador_registradores = 1; //registrador 0 (r0) e reservado
    instrucoes = selecionar();
}

void SelecaoInstrucao::imprimir()
{
    printf("%s\n", instrucoes.c_str());
}

string SelecaoInstrucao::selecionar()
{
    int caso = definir_caso();

    switch (caso)
    {
    case ADD:
        break;
    
    default:
        break;
    }

    return "";
}

int SelecaoInstrucao::definir_caso()
{
    return 0;
}