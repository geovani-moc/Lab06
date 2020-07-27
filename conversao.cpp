#include<map>
#include "conversao.hpp" 
#include "RepreInterm.hpp" 
#include "ArvoreTipada.hpp" 

using namespace std;

Exp_RI* converte_ID(ExpID *exp_id, const map<string, int> &mapa_frame) {
  return new 
    Mem_RI(
           new Binop_RI(string("+"), 
                            new Temp_RI("fp"), 
                        new Const_RI(mapa_frame.find(exp_id->id->nome)->second)));
}

Exp_RI* converte_Num(ExpNum *exp_num) {
  return new Const_RI(atoi(exp_num->num.imagem.c_str()));
}

Exp_RI* converte_Exp(Exp* exp, const map<string, int> &mapa_frame);

Exp_RI* converte_Oper(ExpOper *exp_oper, const map<string, int> &mapa_frame) {
  return new 
    Binop_RI(string(exp_oper->operador.nome),
             converte_Exp(exp_oper->esq, mapa_frame),
             converte_Exp(exp_oper->dir, mapa_frame)
             );
}

/* Solucao nao recomendavel */
Exp_RI* converte_Exp(Exp* exp, const map<string, int> &mapa_frame) {
  if (ExpID * id = dynamic_cast<ExpID*>(exp)) {
    return converte_ID(id,mapa_frame);
  }
  if (ExpNum * num = dynamic_cast<ExpNum*>(exp)) {
    return converte_Num(num);
  }
  if (ExpOper * oper = dynamic_cast<ExpOper*>(exp)) {
    return converte_Oper(oper,mapa_frame);
  }
  return NULL;
} 

RI * representacao_intermediaria_da_unica_atribuicao(Funcao * func){
  int pos_atual_no_frame = -32;
  int delta_frame = 8;
  map<string, int> pos_no_frame_do_id;
  ListaDeclaracao* list_dec = func->decls;
  while(list_dec != NULL) {
    pos_no_frame_do_id[list_dec->dec->identif->nome] = pos_atual_no_frame;
    pos_atual_no_frame -= delta_frame;
    list_dec = list_dec->prox;
  }
  /* unico comando */
  ComandoAtrib * atrib = ((ComandoAtrib *)func->coms->com);
  RI * raiz = new Move_RI(converte_ID(new ExpID(atrib->id),pos_no_frame_do_id), 
                          converte_Exp(atrib->exp,pos_no_frame_do_id));
  return raiz;
}
