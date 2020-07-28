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
    int caso = definir_caso(raiz);

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
    default:
        fprintf(stderr, "Erro: tipo de instrucao nao detectada.\n");
        break;
    }
}

int SelecaoInstrucao::definir_caso(RI *nodo)
{
    if(typeid(*nodo).hash_code() == typeid(Move_RI).hash_code()) return STORE;
    if(typeid(*nodo).hash_code() == typeid(Const_RI).hash_code()) return ADDI;
    if(typeid(*nodo).hash_code() == typeid(Mem_RI).hash_code()) return LOAD;

    if(typeid(*nodo).hash_code() == typeid(Binop_RI).hash_code())
    {
        string temporario = ((Binop_RI*)nodo)->oper;
        if (temporario.compare("+") == 0) return ADD;
        else if (temporario.compare("-") == 0) return SUB;
        else if (temporario.compare("*") == 0) return MUL;
        else if (temporario.compare("/") == 0) return DIV;        
    }
    
    return -1;
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
