#include "selecaoInstrucao.hpp"

SelecaoInstrucao::SelecaoInstrucao(RI *representacao_intermediaria)
{
    contador_registradores = 1; //registrador 0 (r0) e reservado
    instrucoes = selecionar(representacao_intermediaria);
}

void SelecaoInstrucao::imprimir()
{
    printf("%s\n", instrucoes.c_str());
}

string SelecaoInstrucao::selecionar(RI *raiz)
{
    int caso = definir_caso();

    switch (caso)
    {
    case ADD:
        selecionar(((Binop_RI *)raiz)->esq);
        selecionar(((Binop_RI *)raiz)->dir);
        break;
    case SUB:
        break;
    case MUL:
        break;
    case DIV:
        break;
    case LOAD:
        break;
    case STORE:
        break;
    case ADDI:
        break;
    case TEMP:
        break;
    case CONST:// const tslvez nap seja necessario por causa do ADDI
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

void SelecaoInstrucao::instrucao_add()
{
    
}