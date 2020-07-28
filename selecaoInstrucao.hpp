#ifndef SELECAO_INSTRUCAO_HPP
#define SELECAO_INSTRUCAO_HPP

#include "RepreInterm.hpp"

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
    string instrucoes;
    string selecionar(RI *raiz);
    int contador_registradores;
    int definir_caso();

    void SelecaoInstrucao::instrucao_add();

public:
    SelecaoInstrucao(RI *representacao_intermediaria);
    void imprimir();
};

#endif