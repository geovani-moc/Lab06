#ifndef SELECAO_INSTRUCAO_HPP
#define SELECAO_INSTRUCAO_HPP

#include "RepreInterm.hpp"
#include <vector>
#include <string>

#define ADD (1)
#define MUL (2)
#define SUB (3)
#define DIV (4)
#define ADDI (5)
#define SUBI (6)
#define LOAD (7)
#define STORE (8)
#define MOVEM (9)

#define TEMP (10)
#define CONST (11)

using namespace std;

class SelecaoInstrucao
{
private:
    vector<string> instrucoes;
    void selecionar(RI *raiz);
    int contador_registradores;
    int definir_caso();

    void instrucao_ADD(RI *nodo);
    void instrucao_SUB(RI *nodo);
    void instrucao_MUL(RI *nodo);
    void instrucao_DIV(RI *nodo);
    void instrucao_LOAD(RI *nodo);
    void instrucao_STORE(RI *nodo);
    void instrucao_ADDI(RI *nodo);
    void instrucao_TEMP(RI *nodo);

public:
    SelecaoInstrucao(RI *representacao_intermediaria);
    void imprimir();
};

#endif