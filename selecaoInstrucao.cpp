#include "selecaoInstrucao.hpp"

SelecaoInstrucao::SelecaoInstrucao(RI *representacao_intermediaria)
{
    contador_registradores = 1;
    if (-1 == selecionar(representacao_intermediaria))
    {
        fprintf(stderr, "Erro: Erro na selecao de instrucao.\n");
        exit(EXIT_FAILURE);
    }
}

void SelecaoInstrucao::imprimir()
{
    size_t tamanho = instrucoes.size();
    for (size_t i = 0; i < tamanho; ++i) printf("%s\n", instrucoes[i].c_str());
}

int SelecaoInstrucao::selecionar(RI *raiz)
{
    int caso = definir_caso(raiz);

    switch (caso)
    {
    case ADD: return instrucao_ADD(raiz);
    case SUB: return instrucao_SUB(raiz);
    case MUL: return instrucao_MUL(raiz);
    case DIV: return instrucao_DIV(raiz);
    case LOAD: return instrucao_LOAD(raiz);
    case STORE: return instrucao_STORE(raiz);
    case ADDI: return instrucao_ADDI(raiz);
    default:
        fprintf(stderr, "Erro: tipo de instrucao nao detectada.\n");
        exit(EXIT_FAILURE);
    }
    
    return -1;
}

int SelecaoInstrucao::definir_caso(RI *nodo)
{
    if (NULL != dynamic_cast<Move_RI *>(nodo))return STORE;
    else if (NULL != dynamic_cast<Const_RI *>(nodo))return ADDI;
    else if (NULL != dynamic_cast<Mem_RI *>(nodo))return LOAD;
    else if (NULL != dynamic_cast<Binop_RI *>(nodo))
    {
        string temporario = ((Binop_RI *)nodo)->oper;
        if (temporario.compare("+") == 0)return ADD;
        else if (temporario.compare("-") == 0)return SUB;
        else if (temporario.compare("*") == 0)return MUL;
        else if (temporario.compare("/") == 0)return DIV;
    }

    return -1;
}

int SelecaoInstrucao::instrucao_ADD(RI *nodo)
{
    string temporario = "ADD ";
    int registrador1 = selecionar(((Binop_RI *)nodo)->esq);
    int registrador2 = selecionar(((Binop_RI *)nodo)->dir);

    temporario += "r" + to_string(contador_registradores) + " ";
    temporario += "r" + to_string(registrador1) + " ";
    temporario += "r" + to_string(registrador2);
    instrucoes.push_back(temporario);

    return contador_registradores++;
}

int SelecaoInstrucao::instrucao_SUB(RI *nodo)
{
    string temporario = "SUB ";
    int registrador1 = selecionar(((Binop_RI *)nodo)->esq);
    int registrador2 = selecionar(((Binop_RI *)nodo)->dir);

    temporario += "r" + to_string(contador_registradores) + " ";
    temporario += "r" + to_string(registrador1) + " ";
    temporario += "r" + to_string(registrador2);
    instrucoes.push_back(temporario);

    return contador_registradores++;
}

int SelecaoInstrucao::instrucao_MUL(RI *nodo)
{
    string temporario = "MUL ";
    int registrador1 = selecionar(((Binop_RI *)nodo)->esq);
    int registrador2 = selecionar(((Binop_RI *)nodo)->dir);

    temporario += "r" + to_string(contador_registradores) + " ";
    temporario += "r" + to_string(registrador1) + " ";
    temporario += "r" + to_string(registrador2);
    instrucoes.push_back(temporario);

    return contador_registradores++;
}

int SelecaoInstrucao::instrucao_DIV(RI *nodo)
{
    string temporario = "DIV ";
    int registrador1 = selecionar(((Binop_RI *)nodo)->esq);
    int registrador2 = selecionar(((Binop_RI *)nodo)->dir);

    temporario += "r" + to_string(contador_registradores) + " ";
    temporario += "r" + to_string(registrador1) + " ";
    temporario += "r" + to_string(registrador2);
    instrucoes.push_back(temporario);

    return contador_registradores++;
}

int SelecaoInstrucao::instrucao_ADDI(RI *nodo)
{
    string temporario = "ADDI ";
    temporario += "r" + to_string(contador_registradores) + " ";
    temporario += "r0 ";
    temporario += to_string(((Const_RI *)nodo)->valor);
    instrucoes.push_back(temporario);

    return contador_registradores++;
}

int SelecaoInstrucao::instrucao_LOAD(RI *nodo)
{
    string temporario = "LOAD ";
    Binop_RI *auxiliar = (Binop_RI *)(((Move_RI *)nodo)->esq);

    temporario += "r" + to_string(contador_registradores) + " ";
    temporario += ((Temp_RI *)auxiliar->esq)->nome + " ";
    temporario += to_string(((Const_RI *)auxiliar->dir)->valor);

    instrucoes.push_back(temporario);
    return contador_registradores++;
}
int SelecaoInstrucao::instrucao_STORE(RI *nodo)
{
    string temporario = "STORE ";
    Binop_RI *auxiliar = (Binop_RI*)((Mem_RI *)(((Move_RI *)nodo)->esq))->end;

    temporario += ((Temp_RI*) auxiliar->esq)->nome + " ";
    temporario += to_string(((Const_RI*) auxiliar->dir)->valor) + " ";
    temporario += "r" + to_string(selecionar(((Move_RI *)nodo)->dir));

    instrucoes.push_back(temporario);
    return contador_registradores++;
}