#ifndef SELECAO_INSTRUCAO_HPP
#define SELECAO_INSTRUCAO_HPP

#include "RepreInterm.hpp"
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>

#define ADD (1)
#define MUL (2)
#define SUB (3)
#define DIV (4)
#define ADDI (5)
#define SUBI (6)//talvez nao seja necesario 
#define LOAD (7)
#define STORE (8)
#define MOVEM (9) // talvez nao seja necessario

using namespace std;

class SelecaoInstrucao
{
private:
    vector<string> instrucoes;
    int selecionar(RI *raiz);
    int contador_registradores;
    int definir_caso(RI *nodo);

    int instrucao_ADD(RI *nodo);
    int instrucao_SUB(RI *nodo);
    int instrucao_MUL(RI *nodo);
    int instrucao_DIV(RI *nodo);
    int instrucao_LOAD(RI *nodo);
    int instrucao_STORE(RI *nodo);
    int instrucao_ADDI(RI *nodo);

public:
    SelecaoInstrucao(RI *representacao_intermediaria);
    void imprimir();
};

#endif