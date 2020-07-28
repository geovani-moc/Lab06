#ifndef _REPRE_INTERM_HPP_
#define _REPRE_INTERM_HPP_
#include<string>

using namespace std;

class RI;

class Exp_RI;

class Const_RI;
class Temp_RI;
class Binop_RI;
class Mem_RI;
class Move_RI;

class RI {
  public:
  virtual ~RI(){};
};

class Exp_RI : public RI{
  virtual ~Exp_RI(){};
};

class Const_RI : public Exp_RI {
public:
  long long int valor;
  Const_RI(long long int v);
};

class Temp_RI : public Exp_RI {
public:
  string nome; /*nomes possiveis: fp, r0, r1, r2, r3,...*/
  Temp_RI(string n);
};

class Binop_RI : public Exp_RI {
public:
  string oper;
  Exp_RI* esq;
  Exp_RI* dir;
  Binop_RI(string op, Exp_RI* e, Exp_RI* d);
};

class Mem_RI  : public Exp_RI {
public:
  Exp_RI* end;
  Mem_RI(Exp_RI* e);
};

class Move_RI : public RI {
public:
  Exp_RI* esq;
  Exp_RI* dir;
  Move_RI(Exp_RI* e, Exp_RI* d);
};

#endif
