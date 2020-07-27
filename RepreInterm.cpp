#include "RepreInterm.hpp" 

Const_RI::Const_RI(long long int v): valor(v) {}
Temp_RI::Temp_RI(string n):nome(n){}
Binop_RI::Binop_RI(string op, Exp_RI* e, Exp_RI* d) : oper(op), esq(e), dir(d) {}
Mem_RI::Mem_RI(Exp_RI* e) : end(e) {}
Move_RI::Move_RI(Exp_RI*e, Exp_RI* d) : esq(e), dir(d) {}
