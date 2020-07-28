#include "selecaoInstrucao.hpp"

SelecaoInstrucao::SelecaoInstrucao(RI *representacao_intermediaria)
{
    contador_registradores = 1; //registrador 0 (r0) e reservado
    selecionar(representacao_intermediaria);
}

void SelecaoInstrucao::imprimir()
{
    int tamanho = instrucoes.size();
    for (int i = 0; i < tamanho; ++i)
    {
        printf("%s\n", instrucoes[i]);
    }
}

void SelecaoInstrucao::selecionar(RI *raiz)
{
    int caso = definir_caso();

    switch (caso)
    {
    case ADD: instrucao_ADD(raiz);
        break;
    case SUB: instrucao_SUB(raiz);
        break;
    case MUL: instrucao_MUL(raiz);
        break;
    case DIV: instrucao_DIV(raiz);
        break;
    case LOAD: instrucao_LOAD(raiz);
        break;
    case STORE: instrucao_STORE(raiz);
        break;
    case ADDI: instrucao_ADDI(raiz);
        break;
    case TEMP: instrucao_TEMP(raiz);
        break;
    case CONST: // const tslvez nap seja necessario por causa do ADDI
        break;
    default:
        break;
    }
}

int SelecaoInstrucao::definir_caso()
{
    return 0;
}

void SelecaoInstrucao::instrucao_ADD(RI *nodo)
{
}
void SelecaoInstrucao::instrucao_SUB(RI *nodo)
{
}


void SelecaoInstrucao::instrucao_MUL(RI *nodo)
{
}

void SelecaoInstrucao::instrucao_DIV(RI *nodo) {}

void SelecaoInstrucao::instrucao_LOAD(RI *nodo) {}

void SelecaoInstrucao::instrucao_STORE(RI *nodo) {}

void SelecaoInstrucao::instrucao_ADDI(RI *nodo) {}

void SelecaoInstrucao::instrucao_TEMP(RI *nodo) {}