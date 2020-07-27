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

using namespace std;

class SelecaoInstrucao
{
private:
    RI * representcao_intermediaria;
    string instrucoes;
    string selecionar();
    int contador_registradores;
    int definir_caso();
public:
    SelecaoInstrucao(RI * representacao_intermediaria);
    void imprimir();
};




#endif