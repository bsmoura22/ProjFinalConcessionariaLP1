#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

class Executor {
  private:
  Sistema * sistema;
  stringstream ss;
  bool sair = false;
  vector<string> palavras; 
  
  public:
  Executor(Sistema &sistema);

  void iniciar(istream &in, ostream &out);

  string processarLinha(string linha);

  vector<string> quebra_str(string str, const char* op);
};

#endif